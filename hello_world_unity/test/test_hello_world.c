#include "unity.h"
#include "hello_world.h"

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

void test_get_hello_world(void)
{
    char *test_str = NULL;

    TEST_ASSERT_NULL(test_str);

    test_str = get_hello_world();
    TEST_ASSERT_EQUAL_STRING_MESSAGE(
            "Hello World!", test_str, "Expected \"Hello World!\"");
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_get_hello_world);
    return UNITY_END();
}
