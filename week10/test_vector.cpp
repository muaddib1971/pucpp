#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE vector_test
#include <boost/test/unit_test.hpp>
#include "vector.h"
#include <string>

// close to std::array

BOOST_AUTO_TEST_SUITE()

BOOST_AUTO_TEST_CASE(append_item)
{
        vector<int, 5> my_ints{ 1, 3, 5 };
        BOOST_CHECK(my_ints.size() == 3);
        my_ints.add(8);
        BOOST_REQUIRE(my_ints.size() == 4);

        BOOST_CHECK_MESSAGE(my_ints[3] == 8, "Should be 8 but is "
                                                 << my_ints[3]);
}

BOOST_AUTO_TEST_CASE(delete_item)
{
        vector<std::string, 3> my_strings{ "Simon", "Paul", "Ben" };
        if (my_strings.size() != 3)
        {
                BOOST_FAIL("should be size 3 but is " << my_strings.size());
        }
        auto loc = vector<std::string, 3>::iterator(&my_strings[1]);
        my_strings.erase(loc, loc);
        BOOST_CHECK_EQUAL(my_strings.size(), 2);
        BOOST_CHECK_MESSAGE(my_strings[1] != "Paul",
                            "Should not be Paul but is");
}
}
