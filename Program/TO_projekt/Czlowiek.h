#ifndef CZLOWIEK_H_INCLUDED
#define CZLOWIEK_H_INCLUDED

typedef struct Czlowiek_public
{
    char* imie;
    unsigned int wiek;
}Czlowiek_public;

/*//protected - bez 'static' "multiple definition of setImie"
void setImie(Czlowiek_public*inst, char* imie)
{
    inst->imie = imie;
}*/

#endif // CZLOWIEK_H_INCLUDED
