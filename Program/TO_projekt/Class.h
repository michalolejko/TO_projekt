typedef struct Class
{
    int x;
} Class;

Class * Class_cstr (int initX)
{
    struct Class * inst = malloc ( sizeof * inst );
    inst ->x = initX ;
    return inst ;
}

void setX(Class* inst, int x)
{
    inst->x=x;
}

int getX(Class* inst)
{
    return inst->x;
}
