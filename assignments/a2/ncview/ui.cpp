#include "ui.h"
#include "../nc_controller/controller.h"
#include "../model/model.h"
std::unique_ptr<draughts::ncview::ui> draughts::ncview::ui::instance = 
    nullptr;

draughts::ncview::ui::ui(void)
    : thecontroller(draughts::nc_controller::controller::get_instance()),
        themodel(draughts::model::model::get_instance())
{
}

void draughts::ncview::ui::main_menu(void)
{
    draughts::ncview::main_menu menu;
    menu.activate();
}

void draughts::ncview::ui::add_player(void)
{
    draughts::ncview::add_player_window newwin;
    newwin.activate();
}

void draughts::ncview::ui::play_game(void)
{
    try
    {
        player_selection_window newwin(themodel->get_player_list());
        newwin.activate();
    }
    catch(std::exception& ex)
    {
        std::cerr << "Exception: " << std::endl;
    }
}

draughts::ncview::ui * draughts::ncview::ui::get_instance(void)
{
    if(instance == nullptr)
    {
        instance = std::unique_ptr<ui>(new ui());
    }
    return instance.get();
}

void draughts::ncview::ui::delete_instance(void)
{
    instance.reset(nullptr);
}


void draughts::ncview::ui::show_game_window(draughts::ncview::player_pair
    players)
{
    game_window newwin(players);
    newwin.activate();
}

draughts::ncview::ui::~ui(void)
{
}

