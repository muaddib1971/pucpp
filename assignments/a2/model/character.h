namespace model {
    namespace character {
        enum purchase_result {
            SUCCESS,
            NOSHOPKEEPER,
            INSUFFICIENT_FUNDS,
            OTHER_FAILURE
        };
        enum wear_result {
            SUCCESS,
            TOO_LOW_LEVEL,
            WEAR_LOCATION_OCCUPIED,
            NOT_WEARABLE
        };
        class shopkeeper {
            // Attributes
            private :
                room * current_room;
                item*[NUM_WEAR_SLOTS] equipment;
                stl_container<item> inventory;
            // Operations
            public :
                int sell (int id, int value);
                std::string display_wares ();
        };
        enum move_result {
            SUCCESS,
            DOOR_CLOSED,
            NOEXIT_THERE,
            OTHER_FAILURE
        };
    /**
     * \brief As we are only modelling a single player game, there is no need to attach operations to the player other than those that change the player state. Otherwise, these should be represented as command requests sent to the controller. 
     */
        class player {
            // Attributes
            private :
                std::string username;
                /// the hash of the password
                int password;
                const int intelligence;
                const int wisdom;
                const int dexterity;
                const int strength;
                const int constitution;
                int hp;
                int mana;
                int moves;
                /// the room the player is currently in
                room *  location = nullptr;
                item *[NUM_WEAR_SLOTS] equipment;
                stl_container inventory;
                int gold_pieces = 0;
            // Operations
            public :
                purchase_result buy (int listnum);
                purchase_result buy (std::string name);
                int balance ();
                wear_result wear (const item& item);
                void move (direction dir);
        };
    }
}

