#include "main_menu.h"
#include "add_player_window.h"
#include "game_window.h"
#include "player_selection_window.h"

#pragma once

namespace draughts
{
    namespace nc_controller
    {
        class controller;
    }
    namespace model
    {
        class model;
    }
    namespace ncview
    {
        class ui
        {
            draughts::nc_controller::controller * thecontroller;
            draughts::model::model * themodel;
            ui(void);
            static std::unique_ptr<ui> instance;
            public:
                void main_menu(void);

                void add_player(void);

                void play_game(void);

                void show_game_window(player_pair);

                static ui* get_instance();

                static void delete_instance(void);

                virtual ~ui(void);
        };
    }
}
