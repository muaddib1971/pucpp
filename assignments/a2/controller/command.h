#include <string>
#include <functional>
#pragma once
namespace controller {
    /**
     * Implement your commands for the system as children of the command 
     * class. You will need to use inheritance and polymorphism
     */
    class command : public std::function {
        // Attributes
        private :
            static stl_container<command> commands;
        // Operations
        public :
            /**
             * each command will have different parameters
             * \param command_name the name of the command to run
             * \param ... replace this in each child class with the 
             * actual parameters for the command
             * \return bool did it succeed? 
             */
            static bool perform_command (const std::string& command_name, 
                ...);
            static bool add_command (command command);
    };
}
