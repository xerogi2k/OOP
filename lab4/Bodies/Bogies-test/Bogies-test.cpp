#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Bodies/CBody.h"
#include "../Bodies/CSphere.h"
#include "../Bodies/CParallelepiped.h"
#include "../Bodies/CCylinder.h"
#include "../Bodies/CCone.h"
#include "../Bodies/CCompound.h"

TEST_CASE("Test volume calculation for Sphere", "[volume]") {
    CSphere sphere(1.0, 2.0);
    REQUIRE(sphere.GetVolume() == Approx(33.51032).epsilon(0.01));
}

TEST_CASE("Test mass calculation for Parallelepiped", "[mass]") {
    CParallelepiped parallelepiped(2.0, 3.0, 4.0, 1.0);
    REQUIRE(parallelepiped.GetMass() == 24.0);
}

TEST_CASE("Test density calculation for Cone", "[density]") {
    CCone cone(1.0, 2.0, 3.0);
    REQUIRE(cone.GetDensity() == 1.0);
}

TEST_CASE("Test mass calculation for Cylinder", "[mass]") {
    CCylinder cylinder(2.0, 3.0, 1.0);
    REQUIRE(cylinder.GetVolume() == Approx(28.27433).epsilon(0.01));
}

TEST_CASE("Test Compound Body addition and volume calculation", "[compound]") {
    auto compound = std::make_shared<CCompound>();
    auto sphere = std::make_shared<CSphere>(1.0, 2.0);
    auto parallelepiped = std::make_shared<CParallelepiped>(2.0, 3.0, 4.0, 1.0);

    compound->AddChildBody(sphere);
    compound->AddChildBody(parallelepiped);

    REQUIRE(compound->GetVolume() == Approx(45.5103).epsilon(0.01));
}

TEST_CASE("Test Max Body Mass calculation", "[max_body_mass]") {
    std::vector<BodyPtr> bodies;

    auto sphere1 = std::make_shared<CSphere>(1.0, 2.0);
    auto sphere2 = std::make_shared<CSphere>(2.0, 3.0);
    auto parallelepiped = std::make_shared<CParallelepiped>(2.0, 3.0, 4.0, 1.0);

    bodies.push_back(sphere1);
    bodies.push_back(sphere2);
    bodies.push_back(parallelepiped);

    auto maxMassBody = MaxBodyMass(bodies);

    REQUIRE(maxMassBody != nullptr);

    double expectedMass = std::max({ sphere1->GetMass(), sphere2->GetMass(), parallelepiped->GetMass() });
    REQUIRE(maxMassBody->GetMass() == Approx(expectedMass));
}


TEST_CASE("Test Min Weight in Water calculation", "[min_weight_in_water]") {
    std::vector<BodyPtr> bodies;

    auto sphere = std::make_shared<CSphere>(1.0, 2.0);
    auto parallelepiped = std::make_shared<CParallelepiped>(2.0, 3.0, 4.0, 1.0);
    auto cone = std::make_shared<CCone>(1.0, 2.0, 3.0);

    bodies.push_back(sphere);
    bodies.push_back(parallelepiped);
    bodies.push_back(cone);

    auto minWeightBody = MinWeightInWater(bodies);
    REQUIRE(minWeightBody == sphere);
}