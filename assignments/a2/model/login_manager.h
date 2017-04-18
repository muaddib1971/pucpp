namespace model
{
    class login_manager {
        // Attributes
        private :
            std::map<player*, bool> logins;
        // Operations
        public :
            /**
             * \brief you will need to generate a hash from the password - use std::hash for this as that's how I am hashing passwords. 
             * \param name (???)
             * \param password (???) the password actually entered
             * \param player (???)
             * \return bool
             */
            bool login (const std::string & name, const std::string & password, const player & player);
            bool is_logged_in (const player& player);
    };
}
