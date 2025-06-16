#pragma once
#include "CBody.h"

class CCylinder : public CBody 
{
public:
    CCylinder(double density, double baseRadius, double height);
    double GetDensity() const override;
    double GetVolume() const override;
    double GetMass() const override;
    string ToString() const override;

private:
    double m_baseRadius;
    double m_height;
};