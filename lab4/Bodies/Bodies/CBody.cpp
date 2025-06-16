#include "CBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"

BodyPtr MaxBodyMass(const vector<BodyPtr>& bodies)
{
    BodyPtr maxBody = nullptr;
    double maxMass = -1;
    for (const auto& body : bodies) 
    {
        if (body->GetMass() > maxMass)
        {
            maxMass = body->GetMass();
            maxBody = body;
        }
    }
    return maxBody;
}

BodyPtr MinWeightInWater(const vector<BodyPtr>& bodies) 
{
    BodyPtr minWeightBody = nullptr;
    double minWeightDiff = numeric_limits<double>::max();
    for (const auto& body : bodies)
    {
        double weightDiff = body->GetMass() - (1000 * body->GetVolume());
        if (weightDiff < minWeightDiff) 
        {
            minWeightDiff = weightDiff;
            minWeightBody = body;
        }
    }
    return minWeightBody;
}