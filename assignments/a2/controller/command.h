namespace controller {

    /**
     * \brief Implement your commands for the system as children of the command class. You will need to use inheritance and polymorphism
     */

    class command : public std::function {
        // Attributes
        private :
            static stl_container<command> commands;
        // Operations
        public :
            /**
             * \brief each command will have different parameters
             * \param command_name (???)
             * \param ... (???)
             * \return bool
             */
            static bool perform_command (const std::string& command_name,  ...);
            static bool add_command (command command);
    };
}
