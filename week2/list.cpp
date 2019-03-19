#include "list.h"
bool week2::list::list::add(int newnum)
{
        node* newdata = new node(newnum);
        if (!newdata)
        {
                perror("failed to allocate memory");
                return false;
        }
        node* current, *prev;
        if (!head)
        {
                head = newdata;
                return true;
        }
        current = head;
        while (current)
        {
                prev = current;
                current = current->next;
        }
        prev->next = newdata;
        return true;
}

void week2::list::list::print(void)
{
}
week2::list::list::~list()
{
        node* current, *next;
        current = head;
        while (current)
        {
                next = current->next;
                delete current;
                current = next;
        }
}
