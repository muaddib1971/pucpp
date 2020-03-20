#include "list.h"

bool cpt323::list::list::add(int newdata) {
    node* newnode = new node(newdata);
    if (size == 0) {
        head = newnode;
        ++size;
        return true;
    }
    node* prev = NULL;
    node* current;
    for (current = head; current != NULL;
         prev = current, current = current->next) {
        if (current->data >= newdata) {
            break;
        }
    }
    if (!current) {
        prev->next = newnode;
    } else if (!prev) {
        newnode->next = head;
        head = newnode;
    } else {
        prev->next = newnode;
        newnode->next = current;
    }
    ++size;
    return true;
}
