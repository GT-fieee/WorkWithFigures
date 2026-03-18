#include "Sorter.h"
#include "Ellipse.h"
#include <algorithm>

void Sorter::randomFill()
{
    _offsetX = 1.0f + (rand() % 10);
    _offsetY = 1.0f + (rand() % 10);
    _offsetZ = 1.0f + (rand() % 10);
    _radius = 1.0f + (rand() % 5);
    _radiusA = 1.0f + (rand() % 10);
    _radiusB = 1.0f + (rand() % 10);
    _step = 1.0f + (rand() % 10);
}

void Sorter::addToFirstList(int countElements)
{
    _firstList.clear();
    srand(time(NULL));

    int circleCount = 0, ellipseCount = 0, spiralCount = 0;

    for (int i = 0; i < countElements; i++)
    {
        int typesFigure = 1 + rand() % 3;

        switch (typesFigure)
        {
            case 1:
            {
                // задает смещение 
                // //По задумке: чем больше радиус окружности, тем больше на ней точек
                // (координаты центра) радиус
                randomFill();
                _firstList.push_back(make_unique<Circle>(Point(_offsetX, _offsetY, _offsetZ), _radius));
                circleCount++;
                break;
            }
            case 2:
            {
                // (координаты центра), радиусA,радиусB для уравнения эллипса
                randomFill();
                _firstList.push_back(make_unique<Ellipse>(Point(_offsetX, _offsetY, _offsetZ), _radiusA, _radiusB));
                ellipseCount++;
                break;
            }
            case 3:
            {
                // (координаты центра), радиус, шаг (за оборот) для растяжения спирали
                randomFill();
                _firstList.push_back(make_unique<Spiral>(Point(_offsetX, _offsetY, _offsetZ), _radius, _step));
                spiralCount++;
                break;
            }
        }
    }
    cout << "CREATED FIGURE: " << countElements << endl;

    cout << "\n=========================================" << endl
        << "CREATED FIGURES: " << countElements << endl
        << "=========================================" << endl
        << "CIRCLE  : " << circleCount << " figures" << endl
        << "ELLIPSE : " << ellipseCount << " figures" << endl
        << "SPIRAL  : " << spiralCount << " figures" << endl
        << "=========================================\n" << endl;
}

void Sorter::addToSecondList()
{
    _secondList.clear();

    for (const auto& figure : _firstList)
    {
        if (auto circle = dynamic_cast<Circle*>(figure.get()))
        {
            _secondList.push_back(circle);
        }
    }

    sort(_secondList.begin(), _secondList.end(),
        [](Circle* a, Circle* b) {return a->getRadius() < b->getRadius();});

    float radiusesSum = 0;

    if (_secondList.empty())
    {
        cout << "=========================================" << endl;
        cout << "NO CIRCLES FOUND!" << endl;
        cout << "=========================================" << endl;
        return;
    }

    cout << "=========================================" << endl;
    cout << "SORTED CIRCLES ( BY RADIUS ):" << endl;
    cout << "=========================================" << endl;

    for (size_t i = 0; i < _secondList.size(); i++)
    {
        Circle* circle = _secondList[i];
        cout <<  endl << "CIRCLE #" << i + 1
            << " | RADIUS: " << circle->getRadius()
            << " | CENTER: (" << circle->getCenter()._coordX
            << ", " << circle->getCenter()._coordY
            << ", " << circle->getCenter()._coordZ << ")" << endl;

        radiusesSum += circle->getRadius();
    }

    cout << "----------------------------------------" << endl;
    cout << "COUNT CIRCLES: " << _secondList.size() << endl;
    cout << "SUMM RADUSES: " << radiusesSum << endl;
}

void Sorter::showAllFigures()
{
    if (_firstList.empty())
    {
        cout << "----------------------------------------" << endl;
        cout << "FIHGURES NOT FOUND!" << endl;
        cout << "----------------------------------------" << endl;
        return;
    }
    int index = 1;
    float angle = M_PI / 4;

    cout << "----------------------------------------" << endl;
    cout << "POINTS WITH ANGLE PI/4" << endl;
    cout << "----------------------------------------" << endl;

    for (auto& figure : _firstList)
    {
        cout << "Figure #" << index++ << ": " << figure->getName() << endl;

        float x, y, z;
        float dx, dy, dz;

        if (figure->getName() == "CIRCLE")
        {
            float r = figure->getRadius();
            tie(x, y, z) = figure->getPoint(angle, r);
            tie(dx, dy, dz) = figure->getDerivative(angle, r);
        }
        else if (figure->getName() == "ELLIPSE")
        {
            float ra = figure->getRadiusA();
            float rb = figure->getRadiusB();
            tie(x, y, z) = figure->getPoint(angle, ra, rb);
            tie(dx, dy, dz) = figure->getDerivative(angle, ra, rb);
        }
        else if (figure->getName() == "SPIRAL")
        {
            float r = figure->getRadius();
            float s = figure->getStep();
            tie(x, y, z) = figure->getPointSpiral(angle, r, s);
            tie(dx, dy, dz) = figure->getDerivativeSpiral(angle, r, s);
        }

        cout << "X=" << x << " Y=" << y << " Z=" << z << endl;
        cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << endl;
        cout << "----------------------------------------" << endl;
    }
}