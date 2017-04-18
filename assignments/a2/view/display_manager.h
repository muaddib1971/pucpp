#include <string>
#include <tuple>
#include <iostream>
namespace view {
    /**
     * \brief This would be a good place to put your main function
     */
    class display_manager {
        // Attributes
        private :
            controller::command * controller;
            model::model * model;
        // Operations
        public :
            display_welcome_screen ();
            /**
             * \brief see assignment specifications for details on the output here.
             * \param room (???)
             */
            display_room (game_location::room& room);
            /**
             * \brief gets input from the user during a normal turn of the game
             * \return std::string
             */
            std::string get_input ();
            /**
             * \brief displays output asking for username and password and returns a tuple with the username and hash of the password entered
             * \return std::tuple<std::string,int>
             */
            std::tuple<std::string,int> display_login_details ();
    };
}

