#include "Ellipse.h"

Ellipse::Ellipse(const Point& pointCenter, float radiusA, float radiusB)
	: BaseFigure()
{
	_nameFigure = "ELLIPSE";
	_point = pointCenter;
	_radiusA = radiusA;
	_radiusB = radiusB;
	_countPoints = static_cast<int>(_radiusA + _radiusB);
	showPointsFigure(_countPoints);
}


tuple<float, float, float> Ellipse::getPoint(float angleRadian, float radiusA, float radiusB)
{
	return BaseFigure::getPoint(angleRadian, radiusA, radiusB);//{ x, y, z };
}

tuple<float, float, float> Ellipse::getDerivative(float angleRadian, float radiusA, float radiusB)
{
	return BaseFigure::getDerivative(angleRadian, radiusA, radiusB);
}
