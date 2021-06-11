#include "Czlowiek.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Czlowiek
{
    Czlowiek_public;
} Czlowiek;


static void metodaChroniona()
{
    printf("Wywolano metode prywatna\n");
}

//public
static char* getImie(Czlowiek *inst)
{
    return inst->imie;
}










static Czlowiek* Czlowiek_cstr(Czlowiek *inst, char* imie, unsigned int wiek){
    /*struct Czlowiek* this = malloc(sizeof*inst);
    inst = this;*/
    inst->imie = imie;
    inst->wiek = wiek;
    //inst->plec=plec;
    return inst;
}
