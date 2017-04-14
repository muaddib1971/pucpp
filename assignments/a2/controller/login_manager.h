#include <string>
#include <map>
#include "../model/player.h"
namespace controller {
    class login_manager {
        // Attributes
        private :
            std::map<player*, bool> logins;
        // Operations
        public :
            /**
             * \brief you will need to generate a hash from the password - 
             * use std::hash for this as that's how I am hashing passwords. 
             * \param name the name of the player
             * \param password the password actually entered
             * \return bool
             */
            bool login (const std::string & name, 
                const std::string & password, 
                const player & player);
            bool is_logged_in (const player& player);
    };
}
