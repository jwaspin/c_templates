#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

#include "hello.h"
#include "world.h"

struct hello_world
{
    struct hello *h;
    struct world *w;
};

struct hello_world* hello_world_init_new(char *hstr, char *wstr);

void hello_world_print(struct hello_world *hw);

void hello_world_free(struct hello_world *hw);

#endif /* __HELLO_WORLD_H__ */
