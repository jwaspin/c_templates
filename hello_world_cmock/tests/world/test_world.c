#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "unity.h"
#include "world.h"

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

void test_world_init_new(void)
{
    struct world *w = NULL;
    
    w = world_init_new(NULL);
    TEST_ASSERT_NULL(w);

    w = world_init_new("world_test");
    TEST_ASSERT_NOT_NULL(w);
    TEST_ASSERT_EQUAL_STRING("world_test", w->world_string);

    free(w->world_string);
    free(w);
}

void test_get_world_string(void)
{
    struct world *w = NULL;

    w = calloc(1, sizeof(*w));
    TEST_ASSERT_NOT_NULL(w);

    w->world_string = "world_test";
    TEST_ASSERT_EQUAL_STRING("world_test", get_world_string(w));

    free(w);
}

void test_set_world_string(void)
{
    struct world *w = NULL;

    w = calloc(1, sizeof(*w));
    TEST_ASSERT_NOT_NULL(w);

    w->world_string = "world_test";
    TEST_ASSERT_EQUAL_STRING("world_test", w->world_string);

    set_world_string(w, "new_world_test");
    TEST_ASSERT_EQUAL_STRING("new_world_test", w->world_string);

    free(w->world_string);
    free(w);
}

void test_world_free(void)
{
    struct world *w = NULL;

    world_free(w);

    w = calloc(1, sizeof(*w));
    TEST_ASSERT_NOT_NULL(w);

    w->world_string = strdup("world_test");
    TEST_ASSERT_EQUAL_STRING("world_test", w->world_string);

    world_free(w);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_world_init_new);
    RUN_TEST(test_get_world_string);
    RUN_TEST(test_set_world_string);
    RUN_TEST(test_world_free);

    return UNITY_END();
}
