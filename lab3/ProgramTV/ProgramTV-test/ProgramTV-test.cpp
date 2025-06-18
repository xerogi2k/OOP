#define CATCH_CONFIG_MAIN
#include <iostream>
#include "../../../catch2/catch.hpp"
#include "../ProgramTV/TVSet.h"

TEST_CASE("Test TurnOn method", "[CTVSet]")
{
    CTVSet tv;
    tv.TurnOn();
    REQUIRE(tv.GetIsOn() == true);
}


TEST_CASE("Test TurnOff method", "[CTVSet]") {
    CTVSet tv;
    tv.TurnOn();
    tv.TurnOff();
    REQUIRE(tv.GetIsOn() == false);
}

TEST_CASE("Test SelectChannel method", "[CTVSet]") {
    CTVSet tv;
    tv.TurnOn();
    tv.SelectChannel(5);
    REQUIRE(tv.GetCurrentChannel() == 5);
}

TEST_CASE("Test GetChannelName method", "[CTVSet]") {
    CTVSet tv;
    tv.TurnOn();
    tv.SetChannelName(5, "Discovery");
    tv.GetChannelName(5);
    REQUIRE(tv.GetChannelName(5) == "Discovery");
}

TEST_CASE("Test GetChannelByName method", "[CTVSet]") {
    CTVSet tv;
    tv.TurnOn();
    tv.SetChannelName(5, "Discovery");
    REQUIRE(tv.GetChannelByName("Discovery") == 5);
}

TEST_CASE("Test SelectPreviousChannel method", "[CTVSet]") {
    CTVSet tv;
    tv.TurnOn();
    tv.SelectChannel(5);
    tv.SelectChannel(10);
    tv.SelectPreviousChannel();
    REQUIRE(tv.GetCurrentChannel() == 5);
}

TEST_CASE("Test SelectChannel by name method", "[CTVSet]") {
    CTVSet tv;
    tv.TurnOn();
    tv.SetChannelName(5, "Discovery");
    tv.SelectChannelByName("Discovery");
    REQUIRE(tv.GetCurrentChannel() == 5);
}

TEST_CASE("Test DeleteChannelName method", "[CTVSet]") {
    CTVSet tv;
    tv.TurnOn();
    tv.SetChannelName(5, "Discovery");
    tv.DeleteChannelName("Discovery");
    REQUIRE(tv.GetChannelByName("Discovery"));
}
