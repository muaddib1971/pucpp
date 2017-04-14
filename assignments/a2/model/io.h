#include <iostream>
#include <std::string>
#include "model.h"
namespace model 
{
    /**
     * send a reference to the data model to the constructors of each 
     * of these classes
     **/
    namespace io {
        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class ascii_loader {
            // Operations
            public :
                bool load ();
                bool validate ();
        };
        class ascii_saver {
            // Operations
            public :
                bool save (std::string fname);
        };
        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class binary_loader {
            // Operations
            public :
                bool load (std::string fname);
        };
        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class binary_saver {
            // Operations
            public :
                bool save (std::string fname);
        };
    }
}
