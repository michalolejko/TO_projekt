#ifndef PRACOWNIK_H_INCLUDED
#define PRACOWNIK_H_INCLUDED

typedef struct Pracownik
{
    struct Czlowiek;
    unsigned int wynagrodzenie;
}Pracownik;

//public (konstruktor)
Pracownik* Pracownik_cstr(char* imie, unsigned int wynagrodzenie);

//public
char* Pracownik_getImie(struct Pracownik *inst);

#endif // PRACOWNIK_H_INCLUDED
