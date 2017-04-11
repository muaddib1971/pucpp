#include <iostream>
#include <cstdlib>
#include <memory>

struct widget
{
    int size;
    std::unique_ptr<widget[]> widgets;

    widget(void) : size(0), widgets(nullptr){}
    explicit widget(int _size) : size(_size), 
        widgets (std::make_unique<widget[]>(_size)){}

    widget(const widget& w) 
    {
        widgets = std::make_unique<widget[]>(w.size);
        int count;
        size = w.size;
        for(count = 0; count < size; ++count)
        {
            /* do the copying of the widget */
            widgets[count] = std::make_unique<widget>(w.widgets[count]);
        }
    }

    widget operator=(const widget& other)
    {
        /* do the same stuff as in the copy constructor */
        widget w(other);
        return w;
    }

    virtual ~widget()
    {
    }
};

int main(void)
{
    std::string s = "hello";
    /* string(const char * array) */
    widget a(3);
    widget b=a;
}
