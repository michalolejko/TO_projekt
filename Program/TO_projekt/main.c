#include <stdio.h>
//#include "Object.h"
#include "Point.h"

void pointPrezentacja()
{
    //Point.h
    //Pierwsza wersja - tworzenie obiektow bez alokacji pamieci
    //bazujac na strukturze, gdzie wywolywanie metody
    //polega na przekazywaniu jej wskaznika na 'obiekt'
    struct Point p1, p2;

    setX(&p1, 1);
    setX(&p2, 2);
    setY(&p1, 10);
    setY(&p2, 20);
    printf("p1(1,10), p2(2,20)\n");
    printf("x1=%d, y1=%d\n", getX(&p1), getY(&p1));
    printf("x2=%d, y2=%d\n\n", getX(&p2), getY(&p2));

    setX(&p1, getX(&p2));
    setY(&p1, getY(&p2));
    printf("p1(p2.getX(),p2.getY())\n");
    printf("x1=%d, y1=%d\n", getX(&p1), getY(&p1));
}

int main()
{
    pointPrezentacja();
    return 0;
}


