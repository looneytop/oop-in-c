// файл реализации функиий

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

// Class Person
// конструктор(передача значений пользователя в поля)
void init_user(Person* User, int age, const char* name){
    User -> age = age;

    // динам. выделение памяти на имя юзера
    User -> name = (char*)malloc(strlen(name) + 1); // +1 тк \0 не уитывается
    if (User -> name != NULL){
        User -> name = strcpy(User -> name, name);
    }
}

// метод вывода значений(чисто принт)
void print_user(Person* User){
    printf("Name: %s, Age: %d\n", User -> name, User -> age);
}

// деструктор
void destroy_user(Person* User){
    if (User -> name != NULL){
        free(User -> name);
        User -> name = NULL;
    }
}


// Class Rectangle
void init_rect(Rectangle* Rect, double len, double wid){
    Rect -> len = len;
    Rect -> wid = wid;
}

void print_rect_info(Rectangle* Rect){
    printf("Length: %lf, Width: %lf\n", Rect -> len, Rect -> wid);
}

double print_rect_area(Rectangle* Rect){
    double s = (Rect -> len) * (Rect -> wid);

    printf("Area of rectangle: %lf\n", s);
}