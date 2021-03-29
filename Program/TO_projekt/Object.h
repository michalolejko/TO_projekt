/*#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED


#endif // OBJECT_H_INCLUDED*/
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<setjmp.h>
#include<stddef.h>
#include<string.h>
typedef struct Class Class;
typedef struct Class {
    size_t size;
    void * (* constructor) (void * self, va_list * app);
    void * (* destructor) (void * self);
    int * (* clone) (const void * self);
};

void * new (const void * _class, ...)
{
    const struct Class * class = _class;
    void * ptr = calloc(1, class -> size);
    assert(ptr);
    * (const struct Class **) ptr = class;
    if(class -> constructor)
    {
        va_list ap;
        va_start(ap, _class);
        ptr = class -> constructor(ptr, &ap);
        va_end(ap);
    }
    return ptr;
}

void delete (void * self)
{   const struct Class ** cp = self;
    if (self && * cp && (* cp) -> destructor)
        self = (* cp) -> destructor(self);
    free(self);
}
