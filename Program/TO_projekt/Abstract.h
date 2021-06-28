#ifndef ABSTRACT_H_INCLUDED
#define ABSTRACT_H_INCLUDED

typedef struct Abstract
{
    //metoda abstrakcyjna
    void* (*abstractMethod)();
}Abstract;

#endif // ABSTRACT_H_INCLUDED
