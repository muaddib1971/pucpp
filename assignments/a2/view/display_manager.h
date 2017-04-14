#include "../model/model.h"
#include "../controller/command.h"
#include "commandline_processor.h"
#include <cstdlib>
#include <iostream>
namespace view {
    /**
     * \brief This would be a good place to put your main function
     */
    class display_manager {
        // Operations
        public :
            void display_welcome_screen (void);
            void display_room (game_location::room& room);
            std::string get_input (void);
            bool run_command (const std::string& command_string);
    };
}

