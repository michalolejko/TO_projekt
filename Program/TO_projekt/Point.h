typedef struct Point Point;
struct Point {
   int x, y;
   void (*setX)(Point*, int);
   void (*setY)(Point*, int);
   int (*getX)(Point*);
   int (*getY)(Point*);
};

void setX(Point* inst, int x){
    inst->x = x;
}

int getX(Point* inst){
    return inst->x;
}

void setY(Point* inst, int y){
    inst->y = y;
}

int getY(Point* inst){
    return inst->y;
}
/*
void constructor(Point* inst){
    inst->setX = setX;
    inst->getX = getX;
    inst->setY = setY;
    inst->getY = getY;
}
*/
