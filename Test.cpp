#include <iostream>
#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>
#include <algorithm>
#include <map>
#include <stdexcept>

#define ROW_LENGTH 100

using namespace ariel;
TEST_CASE("Good easy cases") {
            Notebook n;
            n.write(0,0,0,Direction::Horizontal,"abcdef");
            n.write(0,1,0,Direction::Vertical,"bcdef");
            CHECK(n.read(0,0,3,Direction::Horizontal,3) == "def");
            CHECK(n.read(0,3,0,Direction::Vertical,3) == "def");
            n.erase(0,0,0,Direction::Horizontal,4);
            CHECK(n.read(0,0,3,Direction::Horizontal,3) == "~ef");
            n.erase(0,5,0,Direction::Vertical,1);
            CHECK(n.read(0,0,0,Direction::Vertical,6) == "~bcde~");
}

TEST_CASE("Good harder cases") {
            Notebook n;
            n.write(0,0,0,Direction::Horizontal,"aaaa");
            n.write(0,0,5,Direction::Horizontal,"bbbb");
            n.write(0,1,3,Direction::Horizontal,"ccc");
            CHECK(n.read(0,0,3,Direction::Horizontal,3) == "a_b");
            CHECK(n.read(0,0,4,Direction::Vertical,2) == "_c");
            n.erase(0,0,4,Direction::Horizontal,1);
            CHECK(n.read(0,0,3,Direction::Horizontal,3) == "a~b");
            CHECK(n.read(0,0,4,Direction::Vertical,3) == "~c_");
            n.erase(0,0,4,Direction::Horizontal,2);
            CHECK(n.read(0,0,3,Direction::Horizontal,3) == "a~~");
}

TEST_CASE("Bad input") {
    Notebook n;
    CHECK_THROWS(n.read(-1,0,0,Direction::Horizontal,3));
    CHECK_THROWS(n.read(0,-1,0,Direction::Vertical,3));
    CHECK_THROWS(n.read(0,0,-1,Direction::Horizontal,3));
    CHECK_THROWS(n.write(-1,0,0,Direction::Horizontal,"qwre"));
    CHECK_THROWS(n.write(0,-1,0,Direction::Vertical,"SDG"));
    CHECK_THROWS(n.write(0,0,-1,Direction::Horizontal,"SAFSF"));
    CHECK_THROWS(n.erase(-1,0,0,Direction::Vertical,3));
    CHECK_THROWS(n.erase(0,-1,0,Direction::Horizontal,3));
    CHECK_THROWS(n.erase(0,0,-1,Direction::Horizontal,3));
    CHECK_THROWS(n.read(0,0,101,Direction::Vertical,3));
    CHECK_THROWS(n.write(0,0,102,Direction::Vertical,"XXXX"));
    CHECK_THROWS(n.erase(0,0,103,Direction::Horizontal,3));

}
