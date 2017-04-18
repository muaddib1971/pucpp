namespace model
{
    namespace game_location {
        enum direction {
            NORTH,
            SOUTH,
            EAST,
            WEST,
            UP,
            DOWN,
            INVALID
        };
        struct connection {
                room * start_room;
                room * end_room;
                model::game_location::direction dir;
        };

        class room {
            // Attributes
                int g_room_no;
                int l_room_no;
                area * myarea;
                std::string name;
                std::string description;
                room*[NUM_DIRECTIONS] exits;
        };
        class area {
            // Attributes
                int id;
                std::string name;
                stl_container<connection> entrances;
                stl_container<connection> exits;
                stl_container<std::unique_ptr<room>> rooms;
                std::string description;
        };
    }
}
