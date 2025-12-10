// файл реализации функиий

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"

// Class Person
static void person_print(Person* self) {
    printf("name: %s, age: %d\n",
        self->name ? self->name : "no name", // захотел красивенько вывести
        self->age);
}

static void person_set_age(Person* self, int new_age) {
    self->age = new_age;
}

// фабрика класса Person
Person* person_create(int age, const char* name) {
    Person* p = (Person*)malloc(sizeof(Person));
    if (!p) {   // чек выделения памяти
        return NULL;
    }

    p->age = age;

    if (name) {
        p->name = (char*)malloc(sizeof(name) + 1); // тк \o или /o отдельный символ
        if (!(p->name)) {   // чек выделения памяти
            free(p);
            return NULL;
        }
        strcpy(p->name, name);
    } else {
        p->name = NULL;
    }

    // привязка методов
    p->print = person_print;
    p->set_age = person_set_age;

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

// фабрика класса Rectangle
Rectangle* rectangle_create(double len, double wid) {
    Rectangle* r = (Rectangle*)malloc(sizeof(Rectangle));
    if (!r) {
        return NULL;
    }

    r->len = len;
    r->wid = wid;
    r->area = rectangle_area;
    r->print = rectangle_print;

    return r;
}

// деструкторы классов
void person_destroy(Person* p) {
    if (!p) return;

    free(p->name);
    free(p);
}

void rectangle_destroy(Rectangle* r) {
    if (!r) return;

    free(r);
}