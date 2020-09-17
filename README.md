# C Templates
Templates for C programs in the form of Hello World examples.  


**This is currently under development. The Hello World and Hello World Unity templates are mostly done, but the cmock template still needs a new makefile and some improvements to the setup/run/cleanup processes, which are underway. The cmock example template is fully functional, so you should still check it out.**

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

That assumes you have git installed. It starts by cloning the unity repository:

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

This template provides a working Hello World example using cmock and unity together. Mocking using cmock required Hello World to be object-oriented. This was done in a rather trivial manner in order to demonstrate both object-oriented programming in C as well as mocking using the cmock framework and unit testing with unity. Once again, you can build and run the example Hello World without running the setup script, but the tests require both unity and cmock to be cloned and the `/bin` directory to be created:

```
./setup.sh
```

This will build the executable `helloworld`:

```
make
```

and then run it using:

```
./helloworld
```

The tests can be built using:

```
make testhello && make testworld && make testhelloworld && make testmain
```

then run the tests using:

```
./bin/testhello; ./bin/testworld; ./bin/testhelloworld; ./bin/testmain
```

**Note: These instructions are likely to change slightly as I clean up the makefile and overall setup process**

My Doh Client repo will be a working example for unity and cmock.

[ThrowTheSwitch]: <https://github.com/ThrowTheSwitch>
