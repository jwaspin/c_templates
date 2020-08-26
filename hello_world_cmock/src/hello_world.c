#include <stdio.h>
#include <stddef.h>
#include "hello_world.h"

static void print_hello_world(struct hello *h, struct world *w)
{
    if ( (h == NULL) || (w == NULL) ) return;

    printf("%s %s!\n", h->hello_string, w->world_string);
}

int testable_main(int argc, char** argv)
{
    struct hello *h = NULL;
    struct world *w = NULL;

    h = hello_init_new("Hello");
    if (h == NULL) return -1;

    w = world_init_new("World");
    if (w == NULL) return -1;

    print_hello_world(h, w);

    return 0;
}
