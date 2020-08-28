#include <stdio.h>
#include <stddef.h>
#include "testable_main.h"
#include "hello_world.h"

int testable_main(int argc, char** argv)
{
    struct hello_world *hw = NULL;

    hw = hello_world_init_new("Hello", "World");
    if (hw == NULL) return -1;

    hello_world_print(hw);
    hello_world_free(hw);

    return 0;
}
