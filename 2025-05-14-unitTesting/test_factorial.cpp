#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch_test_macros.hpp"

#include "factorial.h"

TEST_CASE( "Factorials are computed", "factorial" ) {
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
    REQUIRE( factorial(0) == 1 );
    REQUIRE( factorial(-1) == -1 );
    REQUIRE( factorial(-2) == -1 );
    REQUIRE( factorial(20) == 2432902008176640000 );
    //REQUIRE( factorial(50) == 30414093201713378043612608166064768844377641568960512000000000000L );
}