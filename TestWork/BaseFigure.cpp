#include "BaseFigure.h"

BaseFigure::BaseFigure()
{
	_vectorPoints.push_back(make_unique<Point>(0,0,0));
	_countPoints = _vectorPoints.size();
}

void BaseFigure::calculateAngle(int elementIndex)
{
    _point._angle = (2 * M_PI * elementIndex) / _countPoints;
    _angleRadian = _point._angle;
    _angleDegrees = 360.0f * elementIndex / _countPoints;

    cout << "--- Point " << elementIndex + 1 << " ---" << endl;
    cout << "Angle: " << _angleDegrees << " Degree (" << _angleRadian << " Radian)" << endl;
}

tuple<float, float, float> BaseFigure::getPoint(float angleRadian, float radiusA, float radiusB)
{
	float x = _point._coordX + radiusA * cos(angleRadian);
	float y = _point._coordY + radiusB * sin(angleRadian);
	float z = _point._coordZ;
	return { x, y, z };
}

tuple<float, float, float> BaseFigure::getPoint(float angleRadian, float radius)
{
	float x = _point._coordX + radius * cos(angleRadian);
	float y = _point._coordY + radius * sin(angleRadian);
	float z = _point._coordZ;
	return { x, y, z };
}

tuple<float, float, float> BaseFigure::getPointSpiral(float angleRadian, float radius, float step)
{
    float x = _point._coordX + radius * cos(angleRadian);
    float y = _point._coordY + radius * sin(angleRadian);
    float z = _point._coordZ + (step / (2 * M_PI)) * angleRadian;
    return { x, y, z };
}

tuple<float, float, float> BaseFigure::getDerivative(float angleRadian, float radius)
{
	float dx = -radius * sin(angleRadian);
	float dy = radius * cos(angleRadian);
	float dz = 0;
	return { dx, dy, dz };
}

tuple<float, float, float> BaseFigure::getDerivative(float angleRadian, float radiusA, float radiusB)
{
	float dx = -radiusA * sin(angleRadian);
	float dy = radiusB * cos(angleRadian);
	float dz = 0;
	return { dx, dy, dz };
}

tuple<float, float, float> BaseFigure::getDerivativeSpiral(float angleRadian, float radius, float step)
{
    float dx = -radius * sin(angleRadian);
    float dy = radius * cos(angleRadian);
    float dz = step / (2 * M_PI);
    return { dx, dy, dz };
}

vector<Point> BaseFigure::showPointsFigure(int countPoints)
{ 

    if (countPoints <= 0)
    {
        cout << "ERROR: Count points must be positive!" << endl;
        return vector<Point>();
    }
    else
    {

        _countPoints = countPoints * 4;

        _pointsFigure.clear();
        _pointsFigure.reserve(_countPoints);

        cout << "=========================================" << endl;
        cout << "FIGURE: " << _nameFigure << endl;
        cout << "Points count: " << _countPoints << endl;
        cout << "=========================================" << endl;

        for (int i = 0; i < _countPoints; i++)
        {
            calculateAngle(i);
            float x, y, z;
            float dx, dy, dz;

            if (_nameFigure == "CIRCLE" || _nameFigure == "Circle")
            {
                tie(x, y, z) = getPoint(_angleRadian, _radius);
                tie(dx, dy, dz) = getDerivative(_angleRadian, _radius);
            }
            else if (_nameFigure == "ELLIPSE" || _nameFigure == "Ellipse")
            {
                tie(x, y, z) = getPoint(_angleRadian, _radiusA, _radiusB);
                tie(dx, dy, dz) = getDerivative(_angleRadian, _radiusA, _radiusB);
            }
            else if (_nameFigure == "SPIRAL" || _nameFigure == "Spiral")
            {
                tie(x, y, z) = getPointSpiral(_angleRadian, _radius, _step);
                tie(dx, dy, dz) = getDerivativeSpiral(_angleRadian, _radius, _step);
            }

            Point point(x, y, z, dx, dy, dz);
            point.setAngle(_angleRadian);
            _pointsFigure.push_back(point);
            _pointsFigure.back().showPoint();
        }

        return _pointsFigure;
    }
}

void Point::showPoint() const 
{
	cout << "X: " << _coordX << ", " << "Y: " << _coordY << ", " << "Z: " << _coordZ << endl;
	cout << "dx: " << _dx << " dy: " << _dy << " dz: " << _dz << endl;
	cout << "---------------------------------" << endl;
}

