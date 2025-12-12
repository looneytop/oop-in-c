#include <stdio.h>
#include "class.h"

int main(){     // ну нужно поработать над этим файлов (не воркает)
    
    // class Person
    printf("Test Class Person\n");

    Person* sergey = create_person(18, "Sergey Chirkov", 172.5);

    sergey->print(sergey);
    sergey->setAge(sergey, 19);
    sergey->print(sergey);

    printf("\n");

    Person* kiruha = create_person(18, "Kirill Lepino", 181.0);
    
    if (kiruha == NULL) {
        printf("Failed to create Kirill object!\n");
        sergey->destroy(sergey);
        return 1;
    }
    
    kiruha->print(kiruha);
    kiruha->setAge(kiruha, 23);
    kiruha->print(kiruha);

    // class Rectangle
    printf("Test Class Rectangle\n");

    Rectangle* rect = create_rectangle(5, 3);

    rect->print(rect);
    double area = rect->area(rect);
    double per = rect->perimeter(rect);
    
    printf("Area = %lf, Perimeter = %lf\n", area, per);

    // free memory
    printf("Memory Cleaning Up\n");

    sergey->destroy(sergey);
    kiruha->destroy(kiruha);
    rect->destroy(rect);

    printf("Memory Freed");
    
    return 0;
}
