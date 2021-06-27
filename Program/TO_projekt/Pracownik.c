#include "Czlowiek.h"
#include "Pracownik.h"

Pracownik* Pracownik_cstr(char* imie, unsigned int wynagrodzenie){
    struct Pracownik* inst = malloc(sizeof*inst);
    inst->imie = imie;
    inst->wynagrodzenie = wynagrodzenie;
    inst->getImie = Pracownik_getImie;
    return inst;
}

//public (przes³oniêcie - OVERRIDE):
#ifdef Pracownik
#define getImie(x) Pracownik_getImie(x)
#endif
char* Pracownik_getImie(struct Pracownik *inst)
{
    printf("[OVERRIDED] ");
    return inst->imie;
}
