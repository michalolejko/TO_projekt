#ifndef CZLOWIEK_H_INCLUDED
#define CZLOWIEK_H_INCLUDED

typedef struct Czlowiek Czlowiek;
struct Czlowiek
{
    void * (*Czlowiek_cstr) (Czlowiek*, char*, unsigned int, char);
    struct Czlowiek * this;
    char* nazwisko;
    unsigned int wiek;
    char plec;
    void (*przedstawSie)(Czlowiek*);
    void (*zrobUrodziny) (Czlowiek*);
};

static void dodajRok();

#endif // CZLOWIEK_H_INCLUDED
