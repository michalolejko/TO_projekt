#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Czlowiek.h"
#include "Student.c"

//PRZECI¥¯ENIE-----------------------------------------------------------------
int addi(int a, int b) {
    return a + b;
}

char *adds(char *a, char *b) {
    char *res = malloc(strlen(a) + strlen(b) + 1);
    strcpy(res, a);
    strcat(res, b);
    return res;
}

double addd(double a, double b){
    return a + b;
}

//_Generic - od C11
#define add(a, b) _Generic(a, int: addi, char*: adds, double: addd)(a, b)
//-----------------------------------------------------------------------------

int main()
{
    //tworzenie obiektu
    Czlowiek *czlowiek = (Czlowiek*)Czlowiek_cstr("Jan", 10);
    //pole publiczne[wiek]
    czlowiek->wiek = 16;
    //getImie to metoda publiczna
    printf("%s, lat %d\n", (char*)czlowiek->getImie(czlowiek), czlowiek->wiek);
    czlowiek->setPesel(123456789); //mo¿na zmieniæ na char*
    printf("pesel: %ld\n", (unsigned long)czlowiek->getPesel());
    //usuwanie obiektu:
    free(czlowiek);
    printf("____________________________________________________\n");

    //-----------------------------------------------------------------------------

    //tworzenie obiektu dziedziczacego (RZUTOWANIE W DOL)
    Student *student= (Student*)Czlowiek_cstr("Student Jan", 26);
    student->rok = 1;
    //protected
    student->setPesel(987643210);
    printf("pesel: %ld\n", (unsigned long)czlowiek->getPesel());
    printf("student %d roku, %s, lat %d\n", student->rok, (char*)student->getImie((Czlowiek*)student), student->wiek);
    free(student);
    printf("____________________________________________________\n");

    //-----------------------------------------------------------------------------

    //przeci¹¿enie (_Generic):
    int a = 1, b = 2;
    char *c = "hello ", *d = "world";
    double e = 3, f = 4;
    printf("int:\t%d\n", add(a, b)); // 3
    printf("char*:\t%s\n", add(c, d)); // hello world
    printf("double:\t%lf\n", add(e,f)); // 7

    //-----------------------------------------------------------------------------


    return 0;
}
