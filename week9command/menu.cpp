#include "menu.h"
#include <vector>

const int NUMCOMMANDS = 4;
int main(void)
{
        std::array<std::string, NUMCOMMANDS> strings = { "a item", "b item",
                                                         "c item", "quit" };
        /* command array - should really be constructed int the controller */
        std::array<std::unique_ptr<command>, NUMCOMMANDS> commands = {
                std::make_unique<a_command>(), std::make_unique<b_command>(),
                std::make_unique<c_command>(), std::make_unique<quit_command>()
        };
        menu<NUMCOMMANDS> amenu(strings, std::move(commands));
        while (true)
        {
                amenu.display();
                try
                {
                        int item = amenu.get_input();
                        amenu.perform_operation(item);
                }
                catch (std::exception& ex)
                {
                        std::cerr
                            << "Error: invalid input. Please try again.\n";
                }
        }
}
