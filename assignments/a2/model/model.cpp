#include "model.h"

std::unique_ptr<draughts::model::model> draughts::model::model::instance =
nullptr;

draughts::model::model::model(void) 
{
}

draughts::model::model * draughts::model::model::get_instance(void)
{
    if(instance == nullptr)
    {
        instance = std::unique_ptr<model>(new model);	
    }
    return instance.get();    
}

int draughts::model::model::get_player_score(int playernum)
{
    return EOF;
}

void draughts::model::model::start_game(int plr1, int plr2)
{
}

int draughts::model::model::get_winner()
{
    return EOF;
}

std::string draughts::model::model::get_player_name(int id)
{
    return "";
}

char draughts::model::model::get_token(int x ,int y)
{
    return '\0';
}

void draughts::model::model::make_move(int playernum,
        int startx, int starty, int endx, int endy)
{
}

void draughts::model::model::add_player(const std::string& p)
{
}

bool draughts::model::model::player_exists(const std::string& pname)
{
    return false;
}

int draughts::model::model::get_current_player(void)
{
    return EOF;
}

std::map<int, std::string> draughts::model::model::get_player_list(void) 
    const
{
    std::map<int, std::string> nameslist;
    return nameslist;
}

void draughts::model::model::delete_instance(void)
{
    instance.reset(nullptr);
}


int draughts::model::model::get_width()
{
    return EOF;
}

int draughts::model::model::get_height()
{
    return EOF;
}

draughts::model::model::~model(void)
{
}

