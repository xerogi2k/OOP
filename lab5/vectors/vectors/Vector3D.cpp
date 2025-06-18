#include "Vector3D.h"
#include <cmath>
#include <limits>

using namespace std;

const string DIVISION_BY_ZERO = "Division by zero";

const double epsilon = numeric_limits<double>::epsilon();

CVector3D::CVector3D() : x(0), y(0), z(0) {}

CVector3D::CVector3D(double x0, double y0, double z0) : x(x0), y(y0), z(z0) {}

double CVector3D::GetLength() const
{
    return sqrt(x * x + y * y + z * z);
}

void CVector3D::Normalize()
{
    double length = GetLength();
    if (length != 0) {
        x /= length;
        y /= length;
        z /= length;
    }
}

CVector3D CVector3D::operator+() const
{
    return *this;
}

CVector3D CVector3D::operator-() const
{
    return CVector3D(-x, -y, -z);
}

CVector3D CVector3D::operator+(const CVector3D& other) const
{
    return CVector3D(x + other.x, y + other.y, z + other.z);
}

CVector3D CVector3D::operator-(const CVector3D& other) const
{
    return CVector3D(x - other.x, y - other.y, z - other.z);
}

CVector3D& CVector3D::operator+=(const CVector3D& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

CVector3D& CVector3D::operator-=(const CVector3D& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

CVector3D CVector3D::operator*(double scalar) const
{
    return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D operator*(double scalar, const CVector3D& vector)
{
    return vector * scalar;
}

CVector3D CVector3D::operator/(double scalar) const
{
    if (abs(scalar) < epsilon)
        throw invalid_argument(DIVISION_BY_ZERO);
    return CVector3D(x / scalar, y / scalar, z / scalar);
}

CVector3D& CVector3D::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

CVector3D& CVector3D::operator/=(double scalar)
{
    if (abs(scalar) < epsilon)
        throw invalid_argument(DIVISION_BY_ZERO);
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

bool CVector3D::operator==(const CVector3D& other) const
{
    return (abs(x - other.x) < epsilon &&
        abs(y - other.y) < epsilon &&
        abs(z - other.z) < epsilon);
}

bool CVector3D::operator!=(const CVector3D& other) const
{
    return !(*this == other);
}

ostream& operator<<(ostream& os, const CVector3D& vector)
{
    os << vector.x << ", " << vector.y << ", " << vector.z;
    return os;
}

istream& operator>>(istream& is, CVector3D& vector)
{
    is >> vector.x >> vector.y >> vector.z;
    return is;
}

double DotProduct(const CVector3D& v1, const CVector3D& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

CVector3D CrossProduct(const CVector3D& v1, const CVector3D& v2)
{
    return CVector3D(v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x);
}

CVector3D Normalize(const CVector3D& v)
{
    CVector3D normalized = v;
    normalized.Normalize();
    return normalized;
}
