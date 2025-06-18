#pragma once
#include "CBody.h"

using namespace std;

class CSphere : public CBody 
{
public:
    CSphere(double density, double radius);
    double GetDensity() const override;
    double GetVolume() const override;
    double GetMass() const override;
    string ToString() const override;

private:
    double m_radius;
};