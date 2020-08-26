#ifndef __WORLD_H__
#define __WORLD_H__

struct world
{
    char *world_string;
};

struct world* world_init_new(char *s);
char* get_world_string(struct world *h);
int set_world_string(struct world *w, char *s);
void world_free(struct world *h);

#endif /* __WORLD_H__ */
