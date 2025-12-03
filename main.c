#include <stdio.h>
#include "class.h"

int main(){
    Class user;
    init_user(&user, 11, "Lol Kek");
    print_user(&user);

    destroy_user(&user);

    return 0;
}