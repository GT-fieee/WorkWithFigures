#pragma once
#include <iostream>
#include <List>
#include "Spiral.h"
using namespace std;

class Sorter
{
public:
	void randomFill();
	void addToFirstList(int countElements);
	void addToSecondList();
	void showAllFigures();
private:

	float _offsetX;
	float _offsetY;
	float _offsetZ;
	float _radius;
	float _radiusA;
	float _radiusB;
	float _step;
	int _countElements;
	vector<unique_ptr<BaseFigure>> _firstList;
	vector<Circle*> _secondList;
};

