#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <math.h> 

using namespace std;

class Point {
public:
	Point(float x = 0, float y = 0, float z = 0, float dx = 0, float dy = 0, float dz = 0) : _coordX(x), _coordY(y), _coordZ(z), _dx(dx), _dy(dy), _dz(dz) {};

	void setAngle(float angle) { _angle = angle; }
	float getAngle() { return _angle; }
	void showPoint() const;

	float _coordX, _coordY, _coordZ;
	float _dx, _dy, _dz;
	float _angle;
};
 
class BaseFigure
{
public:
	BaseFigure();

	void calculateAngle(int elementIndex);
	string getName() { return _nameFigure; }
	float getRadius(){ return _radius; }
	float getRadiusA() { return _radiusA; }
	float getRadiusB() { return _radiusB; }
	float getStep() { return _step; }
	
	virtual tuple<float, float, float> getPoint(float angleRadian, float radiusA, float radiusB);
	virtual tuple<float, float, float> getPoint(float angleRadian, float radius);
	virtual tuple<float, float, float> getPointSpiral(float angleRadian, float radius, float step);
	virtual tuple<float, float, float> getDerivative(float angleRadian, float radius);
	virtual tuple<float, float, float> getDerivative(float angleRadian, float radiusA, float radiusB);
	virtual tuple<float, float, float> getDerivativeSpiral(float angleRadian, float radius, float step);
	virtual vector<Point> showPointsFigure(int countPoints);




protected:
	Point _point;
	string _nameFigure;
	float _radius, _radiusA, _radiusB;
	float _angleRadian, _angleDegrees;
	float _step;
	int _countPoints;
	vector<Point> _pointsFigure;
	vector<unique_ptr<Point>> _vectorPoints;
	
};


