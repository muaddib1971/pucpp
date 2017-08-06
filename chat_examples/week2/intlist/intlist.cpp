#include "intlist.h"
/* new typedef */
using ll=linked_list;

/* && means change of ownership */
void ll::node::set_next(std::unique_ptr<ll::node>&& newnext)
{
    next = std::move(newnext);
}

ll::node * ll::node::get_next(void)
{
    return next.get();
}

std::unique_ptr<ll::node>& ll::node::get_next_ptr(void)
{
    return next;
}

int ll::node::get_data(void)
{
    return data;
}

bool ll::add(int data)
{
    node * current;
    node * prev = nullptr;
    std::unique_ptr<ll::node> newnode = std::make_unique<ll::node>(data);
    if(head == nullptr)
    {
        head = std::move(newnode);
        ++size;
        return true;
    }
    current = head.get();//get the pointer held by the unique_ptr
    while(current && current->data < data)
    {
        prev = current;
        current = current->get_next();
    }
    if(!prev)
    {
        newnode->set_next(std::move(head));
        head = std::move(newnode);
    }
    else if(!current)
    {
        prev->set_next(std::move(newnode));
    }
    else
    {
        newnode->set_next(std::move(prev->get_next_ptr()));
        prev->set_next(std::move(newnode));
    }
    ++size;
    return true;
}

bool ll::search(int needle)
{
    return false;
}
