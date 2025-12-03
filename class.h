#ifndef CLASS_H
#define CLASS_H

typedef struct {
    int age;
    char* name;
} Class;

// методы
void init_user(Class* User, int age, const char* name);
void print_user(Class* User);
void destroy_user(Class* User);

#endif 
