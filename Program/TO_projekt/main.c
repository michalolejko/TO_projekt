#include <stdio.h>
#include <stdlib.h>
#include "Czlowiek.h"

struct adres_bajtowy
{
    char* a;
    char* b;
};
union adres
{
    char* ab;
    struct adres_bajtowy badres;
};


int main()
{
    union adres addr;
    addr.badres.a = "abc";
    addr.badres.b = "defg";
    printf ("%s\n",addr.ab);
    return 0;
}




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
