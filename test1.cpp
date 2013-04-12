#define BOOST_TEST_MODULE list_test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "list.h"
#include <iostream>
BOOST_AUTO_TEST_CASE(test_push) {

    list l;
    
    l.push_back(3);
    BOOST_CHECK_EQUAL(l.back(), 3);
    l.push_back(10);
    BOOST_CHECK_EQUAL(l.back(), 10);
    BOOST_CHECK_EQUAL(l.front(), 3);
}

BOOST_AUTO_TEST_CASE(test_iterators) {
    list l;
    int n = 20;
    for(int i = 0; i < n; i++) {
        l.push_back(i);
    }
    for(iterator i = l.begin(); i != l.end(); i++) {
        std::cout << *i << ' ';
    }
    std::cout << *l.end() << std::endl;
    
    for(int i = 0; i < 20; i++) {
        std::cout << l.back() << ' ';
        l.pop_back();
    }
}

        





