#pragma once
#include "BaseFigure.h"

class Circle : public BaseFigure
{
public:
	Circle(const Point& pointCenter, float radius);

	virtual tuple<float, float, float> getPoint(float angleRadian, float radius) override;
	virtual tuple<float, float, float> getDerivative(float angleRadian, float radius) override;
	Point getCenter() { return _point; }
};

