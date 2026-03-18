#include <iostream>
#include "BaseFigure.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Spiral.h"
#include "Sorter.h"

int main()
{
    int menuKey = 0;
    int size = 0;
    Sorter sorter;

    while (menuKey != 4)
    {
        cout <<  endl << "MENU PROGRAM" << endl
            << " ( 1 ) - Create and fill vector figures" << endl
            << " ( 2 ) - Show figuires and points with angle  = PI/4" << endl
            << " ( 3 ) - Create Second vector and sort circles in her" << endl
            << " ( 4 ) - Close program" << endl
            << "CHOOSE MENU ITEM: ";
        cin >> menuKey;

        switch (menuKey)
        {
        case 1:
        {
            cout << endl << "ENTER COUNT FIGURES BY FIRST LIST: " << endl;
            cin >> size;
            if (size <= 0)
                return 1;
            else
            {
                sorter.addToFirstList(size);
            }
            break;
        }

        case 2:
        {
            sorter.showAllFigures();
            break;
        }
        case 3:
        {
            sorter.addToSecondList();
            break;
        }
        }
    }
}