#ifndef PLAYER__HPP
#define PLAYER__HPP

#include "game_location.h"

class player {
    // Attributes
    private :
        std::string username;
        std::string password;
        const int intelligence;
        const int wisdom;
        const int dexterity;
        const int strength;
        const int constitution;
        int hp;
        int mana;
        int moves;
        room *  location = nullptr;
        item *[NUM_WEAR_SLOTS] equipment;
        stl_container inventory;
        int gold_pieces = 0;
    // Operations
    public :
        void look ();
        void look (direction dir);
        void look (const item& item);
        void open (direction dir);
        void close (direction dir);
        purchase_result buy (int listnum);
        purchase_result buy (std::string name);
        int balance ();
        wear_result wear (const item& item);
        void list ();
        move (direction dir);
        quit ();
        bool save (std::ostream& file);
};

#endif
