#include <memory>

class room
{
    std::vector<std::shared_ptr<room>> exits;
    int m_width, m_height;
    std::string m_name;
    public:
        room(int width, int height, const std::string& name)
            : exits(), m_width(width), m_height(height), m_name(name)
        {
        }
        bool add_room(std::shared_ptr<room>& newrm);
        virtual ~room(){}
};

int main(void)
{
    std::vector<std::shared_ptr<room>> house;
    //user input to get details on each room
    //create room instance
    std::shared_ptr<room> newrm = std::make_shared<room>(/* constructor
                                                            details */);
    /* add connections with rooms */

    house.push_back(newrm);
}
