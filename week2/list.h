#include <cstdio>
namespace week2::list
{
        class list
        {
                struct node
                {
                        node* next;
                        int data;
                        node() : next(nullptr), data(0)
                        {
                        }

                        node(int newdata) : next(nullptr), data(newdata)
                        {
                        }
                };

                node* head;
                size_t size;

              public:
                bool add(int);
                void print(void);
                virtual ~list();
        };
}
