OBJS = hello_world.o main.o
TEST_OBJ = test_hello_world.o hello_world.o unity.o
UNITY = unity/src/unity.c unity/src/unity.h unity/src/unity_internals.h

hello_world: $(OBJS)
	gcc -o $@ $(OBJS)

main.o: src/main.c inc/hello_world.h
	gcc -c src/main.c -I inc/

hello_world.o: src/hello_world.c inc/hello_world.h
	gcc -c src/hello_world.c -I inc/

test_hello_world.o: test/test_hello_world.c inc/hello_world.h src/hello_world.c $(UNITY)
	gcc -c test/test_hello_world.c -I inc/ -I unity/src/

test_hello_world: $(TEST_OBJ)
	gcc -o $@ $(TEST_OBJ)

unity.o: $(UNITY)
	gcc -c unity/src/unity.c -I unity/src/

.PHONY: clean
clean: 
	rm hello_world test_hello_world test_hello_world.o unity.o $(OBJS)
