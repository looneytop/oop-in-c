#include <stdio.h>
#include "class.h"

int main(){     // ну нужно поработать над этим файлов (не воркает)
    Person user;
    init_user(&user, 11, "Lol Kek");
    print_user(&user);

    destroy_user(&user);

    printf("---------\n"); // разделяющия линия

    Rectangle rectangle;
    init_rect(&rectangle, 4, 8);
    print_rect_info(&rectangle);

    print_rect_area(&rectangle);

    return 0;
}