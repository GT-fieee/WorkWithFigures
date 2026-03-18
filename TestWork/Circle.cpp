#include "Circle.h"

Circle::Circle(const Point& pointCenter, float radius) : BaseFigure()
{
    _nameFigure = "CIRCLE";
	_radius = radius;
	this->_point = pointCenter;
    _countPoints = _radius;
    showPointsFigure(_countPoints);
}


tuple<float, float, float> Circle::getPoint(float angleRadian, float radius)
{
    return BaseFigure::getPoint(angleRadian, radius);
}

tuple<float, float, float> Circle::getDerivative(float angleRadian, float radius)
{
    return BaseFigure::getDerivative(angleRadian, radius);
}



