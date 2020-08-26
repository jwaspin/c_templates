#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "world.h"

struct world* world_init_new(char *s)
{
    struct world *w = NULL;

    if (s == NULL) return NULL;

    w = calloc(1, sizeof(*w));
    if (w == NULL) return NULL;

    w->world_string = NULL;
    w->world_string = strdup(s);

    return w;
}

char* get_world_string(struct world *w)
{
    return w->world_string;
}

int set_world_string(struct world *w, char *s)
{
    if ( (w == NULL) || (s == NULL) ) return -1;

    w->world_string = NULL;
    w->world_string = strdup(s);

    return 0;
}

void world_free(struct world *w)
{
    if (w == NULL) return;

    if (w->world_string != NULL) free(w->world_string);

    free(w);
}
