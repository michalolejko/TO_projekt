#ifndef ABSTRACTTEST_H_INCLUDED
#define ABSTRACTTEST_H_INCLUDED

typedef struct AbstractTest
{
    struct AbstractTest *this;
    struct Abstract;
}AbstractTest;


void AbstractTest_abstractMethod();
#endif // ABSTRACTTEST_H_INCLUDED
