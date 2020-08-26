#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "hello.h"

struct hello* hello_init_new(char *s)
{
    struct hello *h = NULL;

    if (s == NULL) return NULL;

    h = calloc(1, sizeof(*h));
    if (h == NULL) return NULL;

    h->hello_string = NULL;
    h->hello_string = strdup(s);

    return h;
}

char* get_hello_string(struct hello *h)
{
    return h->hello_string;
}

int set_hello_string(struct hello *h, char *s)
{
    if ( (h == NULL) || (s == NULL) ) return -1;

    h->hello_string = NULL;
    h->hello_string = strdup(s);

    return 0;
}

void hello_free(struct hello *h)
{
    if (h == NULL) return;

    if (h->hello_string != NULL) free(h->hello_string);

    free(h);
}
