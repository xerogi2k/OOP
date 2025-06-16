#include "CCone.h"
#define _USE_MATH_DEFINES
#include <math.h>

const string CONE = "Cone\n";
const string DENSITY = "Density: ";
const string MASS = "Mass: ";
const string VOLUME = "Volume: ";

CCone::CCone(double density, double baseRadius, double height)
    : m_baseRadius(baseRadius), m_height(height) 
{
    m_density = density;
}

double CCone::GetDensity() const
{
    return m_density;
}

double CCone::GetVolume() const 
{
    return (1.0 / 3.0) * M_PI * pow(m_baseRadius, 2) * m_height;
}

double CCone::GetMass() const 
{
    return GetDensity() * GetVolume();
}

string CCone::ToString() const
{
    string ConeInfo = CONE;
    ConeInfo += DENSITY + to_string(GetDensity()) + "\n";
    ConeInfo += MASS + to_string(GetMass()) + "\n";
    ConeInfo += VOLUME + to_string(GetVolume()) + "\n";
    return ConeInfo;
}