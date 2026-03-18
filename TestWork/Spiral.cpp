#include "Spiral.h"

Spiral::Spiral(const Point& center, float radius, float step)
    : Circle(center, radius)  {
    _nameFigure = "SPIRAL";
    _countPoints = _radius;
    _step = step;
    showPointsFigure(_countPoints);
}

tuple<float, float, float> Spiral::getPoint(float angleRadian, float radius, float step)
{
    return BaseFigure::getPointSpiral(angleRadian, radius, step);
}
 
tuple<float, float, float> Spiral::getDerivative(float angleRadian, float radius, float step)
{
    return BaseFigure::getDerivativeSpiral(angleRadian, radius, step);
}
