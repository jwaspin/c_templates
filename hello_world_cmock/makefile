MAIN_OBJ = hello.o world.o hello_world.o testable_main.o main.o
TEST_OBJ = unity.o cmock.o

INC = -I inc/
TEST_INC = -I unity/src/ -I cmock/src/

hello_world:

.PHONY: tests
tests: test_hello_world test_hello test_world test_testable_main

test_hello_world: $(TEST_OBJ) test_hello_world.o
	gcc -o $@ $(TEST_OBJ) test_hello_world.o

test_hello: $(TEST_OBJ)

test_world: $(TEST_OBJ)

test_testable_main: $(TEST_OBJ)

main.o:

testable_main.o:

hello_world.o:

hello.o:

world.o:

unity.o:

cmock.o:


