#include <cstdlib>
#include <memory>
#include <map>
#include "../ncview/ui.h"

#pragma once

namespace draughts
{
    namespace nc_controller
    {

        class command
        {
            protected:
                static ncview::ui * view;

            public:

                command(void)
                {

                }

                virtual void operator()(void) = 0;
                virtual ~command(void){}
        };

        struct exit_command : public command
        {
            virtual void operator()(void) override
            {
                exit(EXIT_SUCCESS);
            }

            virtual ~exit_command(void){}
        };

        struct newgame_command : public command
        {          
            virtual void operator()(void) override
            {
                view->play_game();
                view->main_menu();
            }

            virtual ~newgame_command(void){}
        };

        struct addplayer_command : public command
        {
            virtual void operator()(void) override
            {
                view->add_player();
            }

            virtual ~addplayer_command(void){}
        };

        class select_player_command : public command
        {
            const std::map<int, std::string>& players_ref;
            std::map<int, std::string>& selected_ref;
            int index;
            public:
            select_player_command(
                    const std::map<int, std::string>& players, 
                    std::map<int, std::string>& selected, int ind)

                : players_ref(players), selected_ref(selected), index(ind)
                {
                }

            virtual void operator()(void) override
            {
                const std::map<int, std::string>::const_iterator needle 
                    = players_ref.find(index);
                if(needle == players_ref.cend())
                {
                    throw std::invalid_argument("could not find the "
                        "selected player.");
                }
                selected_ref[index] = needle->second;
            }

            virtual ~select_player_command(void){}
        };

    }
}
