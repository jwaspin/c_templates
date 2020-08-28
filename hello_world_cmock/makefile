.PHONY: testmain
.PHONY: testhelloworld
.PHONY: testhello
.PHONY: testworld

helloworld: src/*.c
	gcc -o bin/helloworld src/*.c -I inc/

testmain: tests/testable_main/*.c src/testable_main.c
	gcc -o bin/testmain src/testable_main.c tests/testable_main/*.c -I inc/ -I tests/testable_main/

testhelloworld: tests/hello_world/*.c src/hello_world.c
	gcc -o bin/testhelloworld src/hello_world.c tests/hello_world/*.c -I inc/ -I tests/hello_world/

testhello: tests/hello/*.c src/hello.c unity/src/unity.c
	gcc -o bin/testhello src/hello.c tests/hello/*.c -I inc/ -I tests/hello/

testworld: tests/world/*.c src/world.c unity/src/unity.c
	gcc -o bin/testworld src/world.c tests/world/*.c -I inc/ -I tests/world/
