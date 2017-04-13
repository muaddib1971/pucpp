#ifndef ITEM__HPP
#define ITEM__HPP

#include "item.h"

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
}

namespace item {
    enum item_type {
        WEAPON,
        ARMOR,
        INVALID
    };
}

namespace item {
    class item {
        // Attributes
        private :
            int id;
            std::string name;
            std::string description;
            item::wear_location wear_loc;
            item::item_type type;
            int armour_class;
    };
}

#endif
