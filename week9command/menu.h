#include <memory>
#include <string>
#include <array>
#include "command.h"
/* all the command stuff mentioned here really is stuff to be done within the
 * controller. I've mixed view and controller logic here */
struct menu_item
{
        std::string text;
        std::unique_ptr<command> operation;
};

template <int I>
class menu
{
        std::array<menu_item, I> menu_items;

      public:
        menu(std::array<std::string, I> strings,
             std::array<std::unique_ptr<command>, I> commands)
        {
                int count;
                for (count = 0; count < I; ++count)
                {
                        menu_items[count].text = strings[count];
                        menu_items[count].operation =
                            std::move(commands[count]);
                }
        }
        void display(void)
        {
                int count = 0;
                for (auto const& item : menu_items)
                {
                        std::cout << count << ") " << item.text << "\n";
                        ++count;
                }
        }

        int get_input(void)
        {
                int result;
                std::string input;
                std::cout << "Please enter a menu item: ";
                std::getline(std::cin, input);
                result = std::stoi(input);
                return result;
        }

        void perform_operation(int index)
        {
                (*(menu_items[index].operation))();
        }
};
