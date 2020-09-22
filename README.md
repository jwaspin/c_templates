# C Templates
Templates for C programs in the form of Hello World examples.  

All of the following instructions assume you are inside the respective directories.


**This is currently under development but is nearly completed. I just finished a more advanced Makefile for the \_cmock template, but need to fix one issue and I want to add an automated way to add new units.**

## Hello World

This is a bare-minimum template with makefile.  
Compile using the simple command:

```
make
```

then run the executable with:

```
./helloworld
```

## Hello World Unity

This template adds unit testing with the Unity framework by [ThrowTheSwitch].  

Everything works with make, so the easiest way to build and run the example is just type:

```
make
```

That assumes you have git installed - alternatively, you could download the framework and place it in a directory named `unity/`. It starts by cloning the unity repository:

```
git clone https://github.com/ThrowTheSwitch/unity.git
```

Then it compiles the hello_world and test_hello_world executables after compiling their object files.

You can also take a more step by step approach:

```
make unity
make build
make run
```

`make run` will execute the test followed by the example.

If you need to clean things up:

```
make clean
```

which will also remove Unity. You can remove only Unity with:

```
make cleanunity
```


## Hello World CMock

This template provides a working Hello World example using cmock and unity together. Mocking using cmock required Hello World to be object-oriented. This was done in a rather trivial manner in order to demonstrate both object-oriented programming in C as well as mocking using the cmock framework and unit testing with unity.  

Because of cmock's dependencies, I have added a more complicated `Makefile` to handle everything. This simple command will do everything:

```
make
```

Unfortunately, right now you need to type that in twice. I'm working on the mock object dependencies so it builds everything with a single `make`, but I'm still learning.  

You can clean everything up with a single

```
make clean
```

or you can target specific options (I'll add a list shortly, for now just look in the makefiles and grep for 'clean').

There are also a couple options to run everything once the first `make` is executed:

```
make run
```

will do it all. Use this one or `make` as much as you like to run both the tests and the program. If you want to run one or the other, append it to the end of 'run', for example:

```
make runtests
```

or you can use:

```
make runprogram
```
 

[ThrowTheSwitch]: <https://github.com/ThrowTheSwitch>
