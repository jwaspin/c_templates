# C Program Template

## Hello World

This is a bare-minimum example for Hello World with a bare-minimum makefile  

## Hello World Unity

This is a Hello World example that includes a basic makefile and unit testing with the Unity framework.  
Navigate into this directory from the command line and type `./setup.sh` then `make` or `make test`.  
To run, type `./bin/helloworld` or `./bin/testhelloworld` respectively.  
Detailed instructions are coming soon.  

## Hello World cmock

This is a Hello World example that adds cmock alongside the unity framework. Because cmock and unity are about unit testing, to understand how powerful their combination is we must take the concept of "Hello World" to an object-oriented mindset. This template breaks the "Hello World" example into 3 new objects: "hello", "world", and "hello_world". By turning this into a set of objects, and specifically having an object that depends on other objects, we can begin to understand how mocking with cmock can effectively simplify writing unit tests.  

This is still a work in progress, so these instructions will be improved with a better makefile and improved supporting scripts. However, if you're wanting to get started now, it's ready to go. This setup process requires ruby and its gem "bundle" to be installed prior to running the setup script. I will add instructions for that as well, but I was able to figure it out easily with some DuckDuckGoogling.  

If you already have ruby installed with its gem "bundle" then you can safely continue with the steps below. If not, the script should fail without breaking anything, but the scripts are untested for errors aside from the few I already fixed. I was running this on a Raspberry Pi, so I didn't need to worry about breaking my system. I always recommend using VM's, EC2, or a Single-board computer that's not being used for anything else when testing new things, but I especially recommend that in this case, at least until I improve the setup process.  

1. Run `./setup` 
2. Run `make testhello && make testworld && make testhelloworld && make testmain && make`  
3. Run `./bin/testhello && ./bin/testworld && ./bin/testhelloworld && ./bin/testmain && ./bin/helloworld`
