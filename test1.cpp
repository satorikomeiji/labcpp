#define BOOST_TEST_MODULE list_test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "list.h"
BOOST_AUTO_TEST_CASE(mytest_case) {

    list l;
    l.push_back(3);
    BOOST_CHECK_EQUAL(l.back(), 3);
    l.push_back(10);
    BOOST_CHECK_EQUAL(l.back(), 10);
    BOOST_CHECK_EQUAL(l.front(), 3);
}

        





