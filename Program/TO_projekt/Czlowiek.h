#ifndef CZLOWIEK_H_INCLUDED
#define CZLOWIEK_H_INCLUDED


//#define public
//#define private static

//protected
unsigned long pesel;

//public
typedef struct Czlowiek
{
    struct Czlowiek*this; //mogloby byc w "Object.h"
    char* imie;
    unsigned int wiek;
    void* (*getImie)(struct Czlowiek*this);
    void* (*setPesel)(long nowyPesel);
    void* (*getPesel)();

}Czlowiek;

//public (konstruktor)
Czlowiek* Czlowiek_cstr(char* imie, unsigned int wiek);

//public
unsigned long czlowiek_getPesel();

//public
void czlowiek_setPesel(unsigned long nowyPesel);

//public
char* czlowiek_getImie(struct Czlowiek *inst);


#endif // CZLOWIEK_H_INCLUDED
