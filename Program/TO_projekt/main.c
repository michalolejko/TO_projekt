#include <stdio.h>
//#include "Object.h"
#include "Point.h"

int main()
{
    struct Point p1, p2;
    constructor(&p1);
    constructor(&p2);

    p1.setX(&p1, 1);
    p2.setX(&p2, 2);
    p1.setY(&p1, 10);
    p2.setY(&p2, 20);
    printf("p1(1,10), p2(2,20)\n");
    printf("x1=%d, y1=%d\n", p1.getX(&p1), p1.getY(&p1));
    printf("x2=%d, y2=%d\n\n", p2.getX(&p2), p2.getY(&p2));

    p1.setX(&p1, p2.getX(&p2));
    p1.setY(&p1, p2.getY(&p2));
    printf("p1(p2.getX(),p2.getY())\n");
    printf("x1=%d, y1=%d\n", p1.getX(&p1), p1.getY(&p1));
    return 0;
}
