#include "Abstract.h"
#include "AbstractTest.h"

AbstractTest* AbstractTest_cstr(){
    struct AbstractTest* inst = malloc(sizeof*inst);
    inst->abstractMethod = AbstractTest_abstractMethod;
    return inst;
}

//public nadpisanie metody abstrakcyjnej:
#ifdef AbstractTest
#define abstractMethod(x) AbstractTest_abstractMethod(x)
#endif
void AbstractTest_abstractMethod()
{
    printf("\nWywolano nadpisana metode abstrakcyjna; \n");
}
