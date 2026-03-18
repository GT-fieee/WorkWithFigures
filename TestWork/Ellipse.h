#pragma once
#include "BaseFigure.h"
class Ellipse : public BaseFigure
{
public:
	Ellipse(const Point& pointCenter, float radiusA, float radiusB);

	tuple<float, float, float> getPoint(float angleRadian, float radiusA, float radiusB) override;
	tuple<float, float, float> getDerivative(float angleRadian, float radiusA, float radiusB) override;	
};

