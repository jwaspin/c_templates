#ifndef __HELLO_H__
#define __HELLO_H__

struct hello
{
    char *hello_string;
};

struct hello* hello_init_new(char *s);

char* get_hello_string(struct hello *h);

int set_hello_string(struct hello *h, char *s);

void hello_free(struct hello *h);

#endif /* __HELLO_H__ */
