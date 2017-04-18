namespace model
{
    class model {
        // Attributes
        private :
            stl_container<player> players;
            stl_container<shop_keeper> shopkeepers;
            stl_container<area> areas;
            std_container<item> items;
        // Operations
        public :
            bool binary_save (const std::string& name);
            bool binary_load (const std::string& name);
            bool ascii_save (const std::string& name);
            bool ascii_load (const std::string & name);
            player& get_player (int id);
            area& get_area (int id);
            room& get_room (int id);
            shop_keeper& get_shop_keeper (int id);
            item& get_item (int id);
    };
}
