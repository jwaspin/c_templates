.PHONY: testhelloworld
.PHONY: testhello
.PHONY: testworld

helloworld: src/*.c
	gcc -o bin/helloworld src/*.c -I inc/

testhelloworld: tests/hello_world/*.c src/hello_world.c unity/src/unity.c
	gcc -o bin/testhelloworld tests/hello_world/*.c src/hello_world.c unity/src/unity.c -I unity/src/ -I inc/

testhello: tests/hello/*.c src/hello.c unity/src/unity.c
	gcc -o bin/testhello tests/hello/*.c src/hello.c unity/src/unity.c -I unity/src/ -I inc/

testworld: tests/world/*.c src/world.c unity/src/unity.c
	gcc -o bin/testworld tests/world/*.c src/world.c unity/src/unity.c -I unity/src/ -I inc/
