#pragma once
#include "CBody.h"

using namespace std;

class CCompound : public CBody 
{
public:
    double GetDensity() const override;
    double GetVolume() const override;
    double GetMass() const override;
    string ToString() const override;
    bool AddChildBody(const BodyPtr& body);

private:
    vector<BodyPtr> m_bodies;

    bool Contains(const BodyPtr& body) const;
};