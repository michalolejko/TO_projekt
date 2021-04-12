typedef struct ChildClass
{
    struct Class super;
    int y;
} ChildClass;

ChildClass * ChildClass_cstr (int initX, int initY)
{
    struct ChildClass * inst = malloc ( sizeof * inst );
    inst ->super.x = initX ;
    inst ->y = initY;
    return inst ;
}


void setY(ChildClass* inst, int y)
{
    inst->y=y;
}

int getY(ChildClass* inst)
{
    return inst->y;
}

