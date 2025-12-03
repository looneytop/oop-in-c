// файл реализации функиий

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

// конструктор(передача значений пользователя в поля)
void init_user(Class* User, int age, const char* name){
    User -> age = age;

    // динам. выделение памяти на имя юзера
    User -> name = (char*)malloc(strlen(name) + 1); // +1 тк \0 не уитывается
    if (User -> name != NULL){
        User -> name = strcpy(User -> name, name);
    }
}

// метод вывода значений(чисто принт)
void print_user(Class* User){
    printf("Name: %s, Age: %d\n", User -> name, User -> age);
}

// деструктор
void destroy_user(Class* User){
    if (User -> name != NULL){
        free(User -> name);
        User -> name = NULL;
    }
}