// файл реализации функиий

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"


// Class Person
static void print_person(Person* self) {
    printf("name: %s, age: %d, height: %lf\n",
        self->name ? self->name : "no name",
        self->age, self->height);
}

static void set_person_age(Person* self, int new_age) {
    self->age = new_age;
}

// деструктор Person
static void person_destroy(Person* p) { 
    if (!p) return;

    if (p->name) {
        free(p->name);
    }
    free(p);
}

// фабрика класса Person
Person* create_person(int age, const char* name, double height) {
    Person* p = (Person*)malloc(sizeof(Person));
    if (!p) {   // чек выделения памяти
        return NULL;
    }

    p->age = age;
    p->height = height;

    if (name) {
        p->name = (char*)malloc(strlen(name) + 1); // +1 для \0
        if (!(p->name)) {   // чек выделения памяти
            free(p);
            return NULL;
        }
        strcpy(p->name, name);
    } else {
        p->name = NULL;
    }

    // привязка методов
    p->print = print_person;
    p->setAge = set_person_age;
    p->destroy = person_destroy;

    return p;
}

// методы Rectangle
static void rectangle_print(Rectangle* self) {
    printf("Rectangle -> len: %lf, wid: %lf\n", self->len, self->wid);
}

static double rectangle_area(Rectangle* self) {
    double s = (self->len) * (self->wid);
    
    return s;
}

static double rectangle_perimeter(Rectangle* self) {
    double p = 2 * (self->len + self->wid);  
    
    return p;
}

// декструктор Rectangle
static void rectangle_destroy(Rectangle* r) { 
    if (!r) return;
    free(r);
}

// фабрика класса Rectangle
Rectangle* create_rectangle(double len, double wid) {
    Rectangle* r = (Rectangle*)malloc(sizeof(Rectangle));
    if (!r) {
        return NULL;
    }

    r->len = len;
    r->wid = wid;
    r->print = rectangle_print;
    r->area = rectangle_area;
    r->perimeter = rectangle_perimeter;
    r->destroy = rectangle_destroy;

    return r;
}   