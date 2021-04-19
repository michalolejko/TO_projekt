#include "Czlowiek.h"
Czlowiek* Czlowiek_cstr(char* nazwisko, unsigned int wiek, char plec){
    struct Czlowiek* inst = malloc(sizeof*inst);
    inst->this = inst;
    inst->nazwisko = nazwisko;
    inst->wiek = wiek;
    inst->plec=plec;
    return inst;
}

//Metoda publiczna
/*public*/void przedstawSie(Czlowiek* inst){
    printf("Jestem %s, mam %d lat.\n", inst->nazwisko, inst->wiek);
}

//Metoda publiczna
/*public*/void zrobUrodziny(Czlowiek* inst){
    printf("Mam dzis urodziny.\n");
    dodajRok(inst);
}

//Metoda prywatna
/*private*/static void dodajRok(Czlowiek *inst){
    inst->wiek++;
}
