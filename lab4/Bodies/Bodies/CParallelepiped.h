#pragma once
#include "CBody.h"

using namespace std;

class CParallelepiped : public CBody 
{
public:
    CParallelepiped(double density, double width, double height, double depth);
    double GetDensity() const override;
    double GetVolume() const override;
    double GetMass() const override;
    string ToString() const override;

private:
    double m_width;
    double m_height;
    double m_depth;
};