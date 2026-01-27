// tests.cpp
//run wget https://github.com/catchorg/Catch2/blob/devel/extras/catch_amalgamated.hpp
#define CATCH_CONFIG_MAIN // This tells Catch2 to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp" // Use the correct header name
#include "../record.h"
#include <vector>

TEST_CASE("addTeam adds a new team to the vector", "[addTeam]") 
{
    std::vector <Record> teams;

    REQUIRE(teams.empty());

    addTeam(teams, "Cyber Ninjas");

    SECTION("Vector size increases") {
        REQUIRE(teams.size() == 1);
    }

    SECTION("Team name is stored correctly") {
        REQUIRE(teams[0].name == "Cyber Ninjas");
    }