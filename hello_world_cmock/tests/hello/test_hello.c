#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "unity.h"
#include "hello.h"

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

void test_hello_init_new(void)
{
    struct hello *h = NULL;

    h = hello_init_new(NULL);
    TEST_ASSERT_NULL(h);

    h = hello_init_new("Hello_test");
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_STRING("Hello_test", h->hello_string);

    free(h->hello_string);
    free(h);
}

void test_get_hello_string(void)
{
    struct hello *h = NULL;

    h = calloc(1, sizeof(*h));
    TEST_ASSERT_NOT_NULL(h);

    h->hello_string = "Hello_test";
    TEST_ASSERT_EQUAL_STRING("Hello_test", get_hello_string(h));

    free(h);
}

void test_set_hello_string(void)
{
    struct hello *h = NULL;

    h = calloc(1, sizeof(*h));
    TEST_ASSERT_NOT_NULL(h);

    h->hello_string = "Hello_test";
    TEST_ASSERT_EQUAL_STRING("Hello_test", h->hello_string);

    set_hello_string(h, "new_Hello_test");
    TEST_ASSERT_EQUAL_STRING("new_Hello_test", h->hello_string);

    free(h->hello_string);
    free(h);
}

void test_hello_free(void)
{
    struct hello *h = NULL;

    h = calloc(1, sizeof(*h));
    TEST_ASSERT_NOT_NULL(h);

    h->hello_string = strdup("Hello_test");
    TEST_ASSERT_EQUAL_STRING("Hello_test", h->hello_string);

    hello_free(h);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_hello_init_new);
    RUN_TEST(test_get_hello_string);
    RUN_TEST(test_set_hello_string);
    RUN_TEST(test_hello_free);

    return UNITY_END();
}
