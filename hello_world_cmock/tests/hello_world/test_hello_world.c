#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "hello_world.h"

#include "Mockhello.h"
#include "Mockworld.h"

void setUp(void)
{
    // No-Op
    return;
}

void tearDown(void)
{
    // No-Op
    return;
}

void test_hello_world_init(void)
{
    struct hello_world *hw = NULL;
    struct hello *h = NULL;
    struct world *w = NULL;
    int retval = 0;

    h = calloc(1, sizeof(*h));
    TEST_ASSERT_NOT_NULL(h);
    w = calloc(1, sizeof(*w));
    TEST_ASSERT_NOT_NULL(w);

    h->hello_string = strdup("Hello");
    TEST_ASSERT_EQUAL_STRING("Hello", h->hello_string);
    w->world_string = strdup("World");
    TEST_ASSERT_EQUAL_STRING("World", w->world_string);

    hello_init_new_ExpectAndReturn("Hello", h);
    world_init_new_ExpectAndReturn("World", w);

    hw = hello_world_init_new("Hello", "World");
    TEST_ASSERT_EQUAL_INT(0, retval);

    free(h->hello_string);
    free(h);
    free(w->world_string);
    free(w);

    free(hw);
}

void test_hello_world_print(void)
{
    TEST_IGNORE_MESSAGE("Intentionally ignored");
    /*
     * This test is ignored because it actually sends a string to stdout.
     * Normally a logging library will be used in place of printf, etc.
     * This function is also just a wrapper for an external function, 
     * which is not something that should be tested here anyway.
     */
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_hello_world_init);
    RUN_TEST(test_hello_world_print);

    return UNITY_END();
}
