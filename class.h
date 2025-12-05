#ifndef CLASS_H
#define CLASS_H

// Класс Person
typedef struct {
    int age;
    char* name;
} Person;

// методы
void init_user(Person* User, int age, const char* name);
void print_user(Person* User);
void destroy_user(Person* User);

// Класс Rectangle
typedef struct {
    double len;
    double wid;
} Rectangle;

void init_rect(Rectangle* Rect, double len, double wid);
void print_rect_info(Rectangle* Rect);
double print_rect_area(Rectangle* Rect); // тут реализован метод Абстракции

#endif 
