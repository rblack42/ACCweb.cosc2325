#include "catch.hpp"
#include "factorial.h"

TEST_CASE( "factorial", "[factorial]") {
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}
