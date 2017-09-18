#include "player_selection_window.h"
#include "../nc_controller/controller.h"

draughts::ncview::player_selection_window::player_selection_window(
        const player_map& players_list 
        )
    : window(), full_list(players_list)
{
}

    std::string 
draughts::ncview::player_selection_window::players_to_string(void)
{
    std::ostringstream out;
    for(auto pair : selected_list){
        out << pair.second << " ";
    }
    return out.str();
}

void draughts::ncview::player_selection_window::activate(void)
{
    if(full_list.size() < NUM_PLAYERS)
    {
        std::cerr << "error: there aren't enough players registered "
            << "to play a game. Go back and register more players." 
            << std::endl;
        return;
    }
    while(selected_list.size() < NUM_PLAYERS)
    {
        if(selected_list.size() > 0)
        {
            std::cout << "You have selected the following player(s) "
                << "to play the game: " 
                << std::endl;
            for(auto & pair : selected_list)
            {
                std::cout << pair.second << std::endl;
            }
        }
        if(selected_list.size() == NUM_PLAYERS)
        {
            std::cout << "starting a game with the following players " 
                << players_to_string() << std::endl;
        }
        std::vector<std::string> strings 
            = player_strings(full_list, selected_list);
        std::vector<std::unique_ptr<nc_controller::command>> actions 
            = create_actions(full_list,  selected_list);
        menu playersmenu("Select a Player to add to the game", 
                strings, std::move(actions));
        playersmenu.activate();
    }
    thecontroller->start_game(selected_list);
}


    std::vector<std::string> 
draughts::ncview::player_selection_window::player_strings(
        const player_map& all_players, player_map& selected)
{
    int size = all_players.size();
    int count = 0;
    std::vector<std::string> menu_strings;
    for(auto  pair : all_players)
    {
        if(++count > size)
        {
            break;
        }
        if(selected.find(pair.first) == selected.end())
        {
            menu_strings.push_back(pair.second);
        }
    }
    return menu_strings;
}

    std::vector<std::unique_ptr<draughts::nc_controller::command>> 
draughts::ncview::player_selection_window::create_actions(
        const player_map& all_players, player_map & selected)
{
    std::vector<std::unique_ptr<nc_controller::command>> commands;
    for(auto & pair : all_players)
    {
        if(selected.find(pair.first) == selected.end()) 
        {
            commands.push_back(
                    std::make_unique<nc_controller::select_player_command>(
                        all_players, selected, pair.first)
                    );
        }
    }
    return commands;
}
