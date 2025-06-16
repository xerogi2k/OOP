#pragma once
#include "CBody.h"

class CCone : public CBody 
{
public:
    CCone(double density, double baseRadius, double height);
    double GetDensity() const override;
    double GetVolume() const override;
    double GetMass() const override;
    string ToString() const override;

private:
    double m_baseRadius;
    double m_height;
};