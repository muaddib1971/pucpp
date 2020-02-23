#include <iostream>
#include <string>
#include <vector>

struct command {
    virtual operator()() = 0;
};

struct play_command : public command {
    virtual operator()() override {}
}

struct scores_command : public command {
    virtual operator()() override {}
};

struct quit_command : public command {
    virtual operator()() override { exit(EXIT_SUCCESS); }
}

struct menu_item {
    std::string text;
    std::unique_ptr<command> action;
};

int main(void) {
    std::vector<menu_item> menu_items{
        {"Play the game", std::make_unique<play_command>()},
        {"High Scores", std::make_unique<scores_command>()}};
    bool quit = false;
    while (!quit) {
        for (int itemno = 0; itemno < menu_items.size(); ++itemno) {
            std::cout << itemno + 1 << ") " << menu_items[itemno].text << "\n";
        }
        int choice;
        // get user input
        //
        (*menu_items[choice].action)();
    }
}
