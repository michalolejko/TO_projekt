#include <stdio.h>
#include <stdlib.h>
//#include "Czlowiek.h"

//klasa czlowiek
/*union Czlowiek2
{
    char* imie;
    int wiek;
};

union Student2
{
    union Czlowiek;
    int semestr;
};*/
/*
typedef struct Czlowiek
{
    union
    {
        char* imie;
        int wiek;
    };
} Czlowiek;

typedef struct Student
{
    struct Czlowiek super;
    int semestr;
}Student;

int main(){
    struct Czlowiek Jan;
    Jan.imie = "Jan";
    printf("Czlowiek:\nImie: %s", Jan.imie);
    Jan.wiek = 10;
    printf("\nWiek: %d", Jan.wiek);
    /*union Student Jan2;
    Jan2.imie = "Jan";
    Jan2.wiek = 20;
     printf("Czlowiek:\nImie: %s,\nWiek: %d", Jan.imie,Jan.wiek);
     printf("Czlowiek:\nImie: %s,\nWiek: %d,\nSemestr: %d", Jan2.imie,Jan2.wiek,Jan2.semestr);*/
    //return 0;
//}

//*/
//bazujac na zrodlach internetowych (linki podane w raporcie do etapu 6)
//bezpieczne dziedziczenie w C

///----------------------------------------------------------------//
//enum zdarzen
enum typy_zdarzen {Myszka, Klawiatura, Nieokreslone};

const char* getNazwaTypuZdarzenia(enum typy_zdarzen typ)
{
    switch (typ)
    {

        case Myszka: return "Myszka";
        case Klawiatura: return "Klawiatura";
        default: return "Nieokreslone";
    }
}
///----------------------------------------------------------------//

///----------------------------------------------------------------//
//klasa zdarzen
typedef struct Zdarzenie_dane
{
    enum typy_zdarzen typ;
} Zdarzenie_dane;

typedef struct Zdarzenie
{
    union
    {
        Zdarzenie_dane zdarzenie;
    } baza;
} Zdarzenie;

#define GETZDARZENIE(self) (&(self)->baza.zdarzenie)
#define typ(self)    (GETZDARZENIE(self)->typ)
///----------------------------------------------------------------//


///----------------------------------------------------------------//
//klasa zdarzen myszy
typedef struct Mysz_dane
{
    /*union
    {
        Zdarzenie_dane zdarzenie;
    } baza;*/
    int posX;
    int posY;
} Mysz_dane;

typedef struct MyszkaKlasa
{
    union
    {
        Zdarzenie_dane zdarzenie;
        Mysz_dane mysz_dane;
    } baza;
} MyszkaKlasa;
#define GETMYSZ(self) (&(self)->baza.mysz_dane)
#define posX(self) (GETMYSZ(self)->posX)
#define posY(self) (GETMYSZ(self)->posY)
///----------------------------------------------------------------//


///----------------------------------------------------------------//
//klasa zdarzen klawiatury
typedef struct Klawiatura_dane
{
    /*union
    {
        Zdarzenie_dane zdarzenie;
    } baza;*/
    char* key;
} Klawiatura_dane;

typedef struct KlawiaturaKlasa
{
    union
    {
        Zdarzenie_dane zdarzenie;
        Klawiatura_dane klawiatura;
    } baza;
} KlawiaturaKlasa;
#define GETKLAWIATURA(self)   (&(self)->baza.klawiatura)
#define key(self) (GETKLAWIATURA(self)->key)
///----------------------------------------------------------------//


void funkcjaWyswietlajaca(MyszkaKlasa myszkaZdarzenie, KlawiaturaKlasa klawiaturaZdarzenie)
{

}

int main()
{
    Zdarzenie zdarzenie;
    MyszkaKlasa myszkaZdarzenie;
    KlawiaturaKlasa klawiaturaZdarzenie;

    //zdarzenie nieokreslone
    typ(&zdarzenie) = Nieokreslone;
        //Zdarzenie myszy
    posX(&myszkaZdarzenie) = 10;
    posY(&myszkaZdarzenie) = 20;
    typ(&myszkaZdarzenie) = Myszka;
    //zdarzenie klawiatury
    typ(&klawiaturaZdarzenie) = Klawiatura;
    key(&klawiaturaZdarzenie) = "Esc";

    printf("Typ zdarzenia nieokreslonego to: [ %s ]\n", getNazwaTypuZdarzenia(typ(&zdarzenie)));
    printf("Typ zdarzenia myszki to: [ %s ]\n", getNazwaTypuZdarzenia(typ(&myszkaZdarzenie)));
    printf("Pozycja myszy: [ x: %d ], [ y: %d ]\n", posX(&myszkaZdarzenie), posY(&myszkaZdarzenie));
    printf("Typ zdarzenia klawiatury to: [ %s ]\n", getNazwaTypuZdarzenia(typ(&klawiaturaZdarzenie)));
    printf("Klawisz: [ %s ]\n", key(&klawiaturaZdarzenie));
    return 0;
}

/*
int main()
{
    Zdarzenie zdarzenie;
    MyszkaKlasa myszkaZdarzenie;
    KlawiaturaKlasa klawiaturaZdarzenie;

    //zdarzenie nieokreslone
    typ(&zdarzenie) = Nieokreslone;

    //Zdarzenie myszy
    posX(myszkaZdarzenie) = 10;
    posY(myszkaZdarzenie) = 20;

    //zdarzenie klawiatury


    printf("Typ zdarzenia nieokreslonego to: [ %s ]", getNazwaTypuZdarzenia(typ(&zdarzenie)));
    return 0;
}
*/



//26.04 (czlowiek)
/*
Czlowiek *kowalski = Czlowiek_cstr("Jan Kowalski", 29, 'm');
    przedstawSie(kowalski);
    zrobUrodziny(kowalski);
    //dodajRok(kowalski); //metoda prywatna
    przedstawSie(kowalski);
    free(kowalski);
    */






/*
///Tworzenie obiektu (a)
puts("Obiekt:");
Class *object = Class_cstr(32); //tworzenie obiektu
printf("object x: %d\n", getX(object)); //pobieranie funkcja get
setX(object, 64); //ustawianie setterem
printf("object x po setterze:%d\n", getX(object)); //pobieranie getterem

///Usuwanie obiektu (a)
free(object);


puts("\nDziedziczacy obiekt - konstruktor x:96, y:128, a potem set 164 i 256:");
///Dziedziczenie obiektu (b)
ChildClass *childObject = ChildClass_cstr(96,128); //tworzenie dziedziczacego obiektu
printf("x: %d, y: %d\n", getX(childObject), getY(childObject)); //pobieranie funkcja get
setX(childObject, 164);
setY(childObject, 256);
printf("x: %d, y: %d\n", getX(childObject), getY(childObject));
free(childObject); //usuwanie obiektu


///Rzutowanie obiektu (b)
puts("\nTworze obiekt typu Class, za pomoca konstruktora ChildClass(32,64):");
Class *object2 = ChildClass_cstr(32, 64);
printf("Rzutowany obiekt x: %d", getX(object2));
printf("\nRzutowany obiekt y: %d", getY(object2));
free(object2); //usuwanie obiektu
puts("\nTworze obiekt typu ChildClass, za pomoca konstruktora Class(32) i setY(64):");
ChildClass *object3 = Class_cstr(32);
printf("Rzutowany obiekt x: %d", getX(object3));
setY(object3, 64);
printf("\nRzutowany obiekt y: %d", getY(object3));
free(object3); //usuwanie obiektu
*/
