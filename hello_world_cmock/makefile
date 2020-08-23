.PHONY: test

helloworld: src/*.c
	gcc -o bin/helloworld src/*.c -I inc/

test: test/*.c src/hello_world.c unity/src/unity.c
	gcc -o bin/testhelloworld test/*.c src/hello_world.c unity/src/unity.c -I unity/src/ -I inc/
