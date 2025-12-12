#ifndef CLASS_H
#define CLASS_H


// class Person
typedef struct Person Person;

struct Person {
    int age;
    char* name;
    double height;

    void (*print)(Person* self);
    void (*setAge)(Person* self, int new_age);
    void (*destroy)(Person* self);
};

// аля конструктор(фабрика)
Person* create_person(int age, const char* name, double height);

// class Rectangle
typedef struct Rectangle Rectangle;

struct Rectangle {
    double len;
    double wid;
    
    void (*print)(Rectangle* self);
    double (*area)(Rectangle* self);
    double (*perimeter)(Rectangle* self);
    void (*destroy)(Rectangle* self);
};

// аля конструктор(фабрика)
Rectangle* create_rectangle(double len, double wid); 

#endif 