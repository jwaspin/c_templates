#!/bin/bash

UNIT=${1}

mkdir tests/$UNIT

cat > tests/${UNIT}/test_${UNIT}.c << EOF
#include <stdio.h>
#include "unity.h"
#include "${UNIT}.h"

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

void test_${UNIT}(void)
{
    TEST_ASSERT_TRUE(true);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_${UNIT});
    return UNITY_END();
}
EOF

cat > inc/${UNIT}.h << EOF
#ifndef __${UNIT^^}_H__
#define __${UNIT^^}_H__

#endif /* __${UNIT^^}_H__ */
EOF

cat > src/${UNIT}.c << EOF
#include "${UNIT}.h"

EOF
