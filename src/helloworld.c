#include <stdio.h>
#include "c_template.h"

int print_hello_world(void)
{
    char *my_str = get_hello_world();
    printf("%s: %s!\n", __func__, my_str);
}

char * get_hello_world(void)
{
    char *hw_str = "Hello World!";

    return hw_str;
}
