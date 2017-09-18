#include "window.h"
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include "menu.h"

#pragma once

namespace draughts
{
    namespace nc_controller
    {
        class controller;
    }
    namespace ncview
    {
        using player_map = std::map<int, std::string>;
        const int NUM_PLAYERS = 2;
        class player_selection_window : public window
        {
            const std::map<int,std::string> full_list;
            std::map<int,std::string> selected_list;
            public:
            player_selection_window(const player_map&);
            virtual void activate(void) override;
            std::string players_to_string(void);
            static std::vector<std::string> player_strings(const player_map&, 
                player_map&);
            static std::vector<std::unique_ptr<nc_controller::command>>
                create_actions(const player_map&, player_map&);
            virtual ~player_selection_window(void){}
        };
    }
}
