#pragma once
#include "Circle.h"
class Spiral :  public Circle
{
public:
    Spiral(const Point& center, float radius, float step);

    virtual tuple<float, float, float> getPoint(float angleRadian, float radius, float step) override;
    virtual tuple<float, float, float> getDerivative(float angleRadian, float radius, float step) override;
};

