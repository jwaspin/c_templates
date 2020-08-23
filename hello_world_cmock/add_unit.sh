#!/bin/bash

UNIT=${1}

mkdir tests/$UNIT

cat tests/template/template01 > tests/${UNIT}/test_${UNIT}.c
echo "#include \"${UNIT}.h\"" >> tests/${UNIT}/test_${UNIT}.c
cat tests/template/template02 >> tests/${UNIT}/test_${UNIT}.c
echo "void test_${UNIT}(void)" >> tests/${UNIT}/test_${UNIT}.c
cat tests/template/template03 >> tests/${UNIT}/test_${UNIT}.c
echo "    RUN_TEST(test_object);" >> tests/${UNIT}/test_${UNIT}.c
cat tests/template/template04 >> tests/${UNIT}/test_${UNIT}.c

echo "#ifndef __${UNIT}_H__" >  inc/${UNIT}.h
echo "#define __${UNIT}_H__" >> inc/${UNIT}.h
echo >> inc/${UNIT}.h
echo "#endif /* __${UNIT}_H__ */" >> inc/${UNIT}.h

echo "#include \"${UNIT}.h\"" > src/${UNIT}.c
echo >> src/${UNIT}.c
