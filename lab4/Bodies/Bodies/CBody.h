#pragma once
#include <memory>
#include <string>
#include <vector>

using namespace std;

class CBody
{
public:
    virtual double GetDensity() const = 0;
    virtual double GetVolume() const = 0;
    virtual double GetMass() const = 0;
    virtual string ToString() const = 0;
    virtual ~CBody() {}

protected:
    double m_density;
};

using BodyPtr = shared_ptr<CBody>;

BodyPtr MaxBodyMass(const vector<BodyPtr>& bodies);
BodyPtr MinWeightInWater(const vector<BodyPtr>& bodies);