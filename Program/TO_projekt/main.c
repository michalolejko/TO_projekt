#include <stdio.h>
#include <stdlib.h>
#include "Czlowiek.c"
#include "Student.c"

int main()
{
    //tworzenie obiektu
    Czlowiek czlowiek;
    czlowiek.imie = "Jan";
    czlowiek.wiek = 10;
    printf("%s, lat %d\n", czlowiek.imie, czlowiek.wiek);
    //getImie to metoda publiczna
    printf("%s\n", getImie(&czlowiek));

    //tworzenie obiektu dziedzicz¹cego
    Student student;
    student.imie = "Student Jan";
    student.wiek = 20;
    student.rok = 1;
    printf("student %d roku, %s, lat %d\n", student.rok, student.imie, student.wiek);
    //getImie to metoda publiczna z klasy czlowiek
    printf("%s\n", getImie(&student));
    return 0;
    //obiekty są usuwane wraz z końcem cyklu programu
}
