#include "Czlowiek.h"
#include <stdlib.h>


//public
Czlowiek* Czlowiek_cstr(char* imie, unsigned int wiek){
    struct Czlowiek* inst = malloc(sizeof*inst);
    inst->this = inst;
    inst->imie = imie;
    inst->wiek = wiek;
    inst->getImie = czlowiek_getImie;
    inst->setPesel = czlowiek_setPesel;
    inst->getPesel = czlowiek_getPesel;

    return inst;
}

//public
unsigned long czlowiek_getPesel()
{
    return pesel;
}

//public
void czlowiek_setPesel(unsigned long nowyPesel)
{
    pesel = nowyPesel;
}

//public
char* czlowiek_getImie(struct Czlowiek *inst)
{
    return inst->imie;
}


