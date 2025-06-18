#include "CParallelepiped.h"

const string PARALLELEPIPED = "Parallelepiped\n";
const string DENSITY = "Density: ";
const string MASS = "Mass: ";
const string VOLUME = "Volume: ";

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
    : m_width(width), m_height(height), m_depth(depth)
{
    m_density = density;
}

double CParallelepiped::GetDensity() const
{
    return m_density;
}

double CParallelepiped::GetVolume() const 
{
    return m_width * m_height * m_depth;
}

double CParallelepiped::GetMass() const 
{
    return GetDensity() * GetVolume();
}

string CParallelepiped::ToString() const 
{
    string ParallelepipedInfo = PARALLELEPIPED;
    ParallelepipedInfo += DENSITY + to_string(GetDensity()) + "\n";
    ParallelepipedInfo += MASS + to_string(GetMass()) + "\n";
    ParallelepipedInfo += VOLUME + to_string(GetVolume()) + "\n";

    return ParallelepipedInfo;
}