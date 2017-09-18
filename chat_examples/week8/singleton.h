#include <memory>
#include <cstdlib>

class singleton
{
    static std::unique_ptr<singleton> instance;
    singleton()
    {
    }
    public:
        static singleton * get_instance(void)
        {
            if(instance == nullptr)
            {
                //can't use std::make_unique!!! 
                instance = std::unique_ptr<singleton>(
                    new singleton()
                );
            }
            return instance.get();
        }

        static void doit(void);

        virtual ~singleton()
        {
        }
};
