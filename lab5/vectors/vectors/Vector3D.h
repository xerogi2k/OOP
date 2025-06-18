#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class CVector3D
{
public:
    CVector3D();

    CVector3D(double x0, double y0, double z0);

    double GetLength() const;

    void Normalize();

    CVector3D operator+() const;

    CVector3D operator-() const;

    CVector3D operator+(const CVector3D& other) const;

    CVector3D operator-(const CVector3D& other) const;

    CVector3D& operator+=(const CVector3D& other);

    CVector3D& operator-=(const CVector3D& other);

    CVector3D operator*(double scalar) const;
    friend CVector3D operator*(double scalar, const CVector3D& vector); // const scalar const функция

    CVector3D operator/(double scalar) const;

    CVector3D& operator*=(double scalar);

    CVector3D& operator/=(double scalar);

    bool operator==(const CVector3D& other) const;

    bool operator!=(const CVector3D& other) const;

    friend std::ostream& operator<<(std::ostream& os, const CVector3D& vector);

    friend std::istream& operator>>(std::istream& is, CVector3D& vector);

    double x, y, z;
};

double DotProduct(const CVector3D& v1, const CVector3D& v2);

CVector3D CrossProduct(const CVector3D& v1, const CVector3D& v2);

CVector3D Normalize(const CVector3D& v);

#endif
