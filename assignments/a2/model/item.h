namespace model
{
    namespace item {
        enum wear_location {
            WRISTS,
            ARMS,
            HANDS,
            LEGS,
            FEET,
            HEAD,
            TORSO,
            SHIELD,
            WIELDED,
            NO_LOC = -1
        };
        enum item_type {
            WEAPON,
            ARMOR,
            INVALID
        };
        class item {
            // Attributes
            private :
                int id;
                std::string name;
                std::string description;
                model::item::wear_location wear_loc;
                model::item::item_type type;
                int armour_class;
        };
    }
}
