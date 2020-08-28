#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "hello_world.h"

struct hello_world* hello_world_init_new(char *hstr, char *wstr)
{
    struct hello_world *hw = NULL;

    if ( (hstr == NULL) || (wstr == NULL) ) return NULL;

    hw = calloc(1, sizeof(*hw));
    if (hw == NULL) return NULL;

    hw->h = hello_init_new(hstr);
    if (hw->h == NULL) goto err_hello;

    hw->w = world_init_new(wstr);
    if (hw->w == NULL) goto err_world;

    return hw;

err_world:
    hello_free(hw->h);
    hw->h = NULL;

err_hello:
    free(hw);
    return NULL;
}

void hello_world_print(struct hello_world *hw)
{
    if (hw == NULL) return;

    printf("%s %s!\n", hw->h->hello_string, hw->w->world_string);
}

void hello_world_free(struct hello_world *hw)
{
    if (hw == NULL) return;

    if (hw->h != NULL)
    {
        hello_free(hw->h);
        hw->h = NULL;
    }

    if (hw->w != NULL)
    {
        world_free(hw->w);
        hw->w = NULL;
    }

    free(hw);
}
