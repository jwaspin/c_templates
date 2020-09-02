OBJS = hello_world.o main.o

hello_world: $(OBJS)
	gcc -o $@ $(OBJS)

main.o: src/main.c inc/hello_world.h
	gcc -c src/main.c -I inc/

hello_world.o: src/hello_world.c inc/hello_world.h
	gcc -c src/hello_world.c -I inc/

.PHONY: clean
clean: 
	rm hello_world $(OBJS)
