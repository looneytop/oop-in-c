#ifndef CLASS_H
#define CLASS_H

// то что видит юзер
// Класс Person
typedef struct Person {
    int age;
    char* name;

    void (*print)(struct Person* self);
    void (*set_age)(struct Person* self, int new_age);
} Person;

// Класс Rectangle
typedef struct Rectangle {
    double len;
    double wid;

    void (*print)(struct Rectangle* self);
    double (*area)(struct Rectangle* self);
} Rectangle;

// деструкторы(юзер не видит этого)
void person_destroy(Person* p);
void rectangle_destroy(Rectangle* r);

#endif 