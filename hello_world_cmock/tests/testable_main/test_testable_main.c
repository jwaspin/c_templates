#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "testable_main.h"

#include "Mockhello_world.h"

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

void test_testable_main(void)
{
    struct hello_world *hw = NULL;
    int retval = 0;

    hw = calloc(1, sizeof(*hw));
    hw->h = calloc(1, sizeof(*hw->h));
    hw->h->hello_string = strdup("Hello");
    hw->w = calloc(1, sizeof(*hw->w));
    hw->w->world_string = strdup("World");

    hello_world_init_new_ExpectAndReturn("Hello", "World", hw);
    hello_world_print_Expect(hw);
    hello_world_free_Expect(hw);

    retval = testable_main(0, NULL);
    TEST_ASSERT_EQUAL_INT(0, retval);

    free(hw->w->world_string);
    free(hw->w);
    free(hw->h->hello_string);
    free(hw->h);
    free(hw);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_testable_main);

    return UNITY_END();
}
