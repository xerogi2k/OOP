#define CATCH_CONFIG_MAIN
#include "../vectors/Vector3D.h"
#include "../../../catch2/catch.hpp"

TEST_CASE("Default Constructor")
{
    CVector3D vector;
    REQUIRE(vector.x == 0);
    REQUIRE(vector.y == 0);
    REQUIRE(vector.z == 0);
}

TEST_CASE("Parameterized Constructor")
{
    CVector3D vector(1, 2, 3);
    REQUIRE(vector.x == 1);
    REQUIRE(vector.y == 2);
    REQUIRE(vector.z == 3);
}

TEST_CASE("GetLength")
{
    CVector3D vector(3, 4.6, 6.5);
    REQUIRE(vector.GetLength() == Approx(8.5094065598));
}

TEST_CASE("GetLength - Zero Vector")
{
    CVector3D vector(0, 0, 0);
    REQUIRE(vector.GetLength() == 0);
}

TEST_CASE("Normalize")
{
    CVector3D vector(3, 4.9, 4.7);
    vector.Normalize();
    REQUIRE(vector.x == Approx(0.4041526728));
    REQUIRE(vector.y == Approx(0.6601160323));
    REQUIRE(vector.z == Approx(0.6331725207));
}

TEST_CASE("Unary Plus Operator")
{
    CVector3D vector(1, 2, 3);
    CVector3D result = +vector;
    REQUIRE(result == vector);
}

TEST_CASE("Unary Minus Operator")
{
    CVector3D vector(1, 2, 3);
    CVector3D result = -vector;
    REQUIRE(result == CVector3D(-1, -2, -3));
}

TEST_CASE("Binary Addition Operator")
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    CVector3D result = v1 + v2;
    REQUIRE(result == CVector3D(5, 7, 9));
}

TEST_CASE("Binary Subtraction Operator")
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    CVector3D result = v1 - v2;
    REQUIRE(result == CVector3D(-3, -3, -3));
}

TEST_CASE("Compound Addition Operator")
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    v1 += v2;
    REQUIRE(v1 == CVector3D(5, 7, 9));
}

TEST_CASE("Compound Subtraction Operator")
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    v1 -= v2;
    REQUIRE(v1 == CVector3D(-3, -3, -3));
}

TEST_CASE("Scalar Multiplication Operator")
{
    CVector3D vector(1, 2, 3);
    CVector3D result = vector * 2;
    REQUIRE(result == CVector3D(2, 4, 6));
}

TEST_CASE("Scalar Multiplication Operator Zero")
{
    CVector3D vector(1, 2, 3);
    CVector3D result = vector * 0;
    REQUIRE(result == CVector3D(0, 0, 0));
}

TEST_CASE("Scalar Multiplication Operator (Reverse)")
{
    CVector3D vector(1, 2, 3);
    CVector3D result = 2 * vector;
    REQUIRE(result == CVector3D(2, 4, 6));
}

TEST_CASE("Scalar Division Operator") {
    CVector3D vector(2, 4, 6);
    CVector3D result = vector / 2;
    REQUIRE(result == CVector3D(1, 2, 3));
}

TEST_CASE("Scalar Multiplication Assignment Operator")
{
    CVector3D vector(1, 2, 3);
    vector *= 2;
    REQUIRE(vector == CVector3D(2, 4, 6));
}

TEST_CASE("Scalar Division Assignment Operator")
{
    CVector3D vector(2, 4, 6);
    vector /= 2;
    REQUIRE(vector == CVector3D(1, 2, 3));
}

TEST_CASE("Scalar Division Operator - Zero Scalar")
{
    CVector3D vector(2, 4, 6);
    REQUIRE_THROWS_AS(vector / 0, std::invalid_argument);
}

TEST_CASE("Scalar Division Assignment Operator - Zero Scalar")
{
    CVector3D vector(2, 4, 6);
    REQUIRE_THROWS_AS(vector /= 0, std::invalid_argument);
}

TEST_CASE("Equality Operator")
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(1, 2, 3);
    REQUIRE(v1 == v2);
}

TEST_CASE("Inequality Operator")
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    REQUIRE(v1 != v2);
}

TEST_CASE("Output Operator")
{
    CVector3D vector(1, 2, 3);
    std::ostringstream oss;
    oss << vector;
    REQUIRE(oss.str() == "1, 2, 3");
}

TEST_CASE("Input Operator")
{
    CVector3D vector;
    std::istringstream iss("4 5 6");
    iss >> vector;
    REQUIRE(vector == CVector3D(4, 5, 6));
}

TEST_CASE("Dot Product")
{
    CVector3D v1(1, 2.35634, 3.255554);
    CVector3D v2(4.6456546, 5.545654, 6);
    REQUIRE(DotProduct(v1, v2) == Approx(37.2464249464));
}

TEST_CASE("Dot Product - Orthogonal Vectors")
{
    CVector3D v1(1, 0, 0);
    CVector3D v2(0, 1, 0);
    REQUIRE(DotProduct(v1, v2) == 0);
}
TEST_CASE("Cross Product")
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    CVector3D result = CrossProduct(v1, v2);
    REQUIRE(result == CVector3D(-3, 6, -3));
}

TEST_CASE("Cross Product - Parallel Vectors")
{
    CVector3D v1(1, 0, 0);
    CVector3D v2(2, 0, 0);
    CVector3D result = CrossProduct(v1, v2);
    REQUIRE(result == CVector3D(0, 0, 0));
}

TEST_CASE("Normalize Function")
{
    CVector3D vector(3, 4, 0);
    CVector3D result = Normalize(vector);
    REQUIRE(result.x == Approx(0.6));
    REQUIRE(result.y == Approx(0.8));
    REQUIRE(result.z == 0);
}


TEST_CASE("Normalize - Zero Vector")
{
    CVector3D vector(0, 0, 0);
    vector.Normalize();
    REQUIRE(vector.x == 0);
    REQUIRE(vector.y == 0);
    REQUIRE(vector.z == 0);
}

