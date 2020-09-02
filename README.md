# C Templates

Templates for C programs in the form of Hello World. 

## Hello World

This is a bare-minimum template with makefile.

## Hello World Unity

This template adds unit testing with the Unity framework by [ThrowTheSwitch].  
To run the Hello World example, you need to clone the unity framework: 

```
git clone https://github.com/ThrowTheSwitch/unity.git
```

The unity framework is specifically for unit testing, so you can still run the Hello World example without cloning it. The example can be built using the simple command:

```
make
```

which builds an executable named `hello_world`. Run it using:

```
.helloworld
```

In order to run the tests, you must clone the unity framework, currently using the setup script above. Once that is finished you can build the tests using:

```
make test
```  

which will build an executable called `test_hello_world` and place it in the `/bin` directory. Run the tests using:

```
./bin/testhelloworld
```

To cleanup executables and object files:

```
make clean
```


**Note: These instructions are likely to change slightly as I clean up the makefile and overall setup process**

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
