SHELL := /bin/sh
CC := gcc

INCDIR := inc/
SRCDIR := src/
OBJDIR := build/obj/
BINDIR := build/bin/
TESTDIR := test/
UT_LIB := unity
UT_INC := unity/src/
UT_SRC := unity/src/

vpath %.h $(INCDIR)
vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)
vpath %.c $(TESTDIR)
vpath %.h $(UT_INC)
vpath %.c $(UT_SRC)

PATHS := $(wildcard $(SRCDIR)*.c)
SRCS := $(subst $(SRCDIR),,$(PATHS))
OBJS := $(patsubst %.c,%.o,$(SRCS))
PATHO := $(addprefix $(OBJDIR),$(OBJS))
PATHOX := $(filter-out $(OBJDIR)main.o,$(PATHO))

PATHTS := $(wildcard $(TESTDIR)*.c)
TSRCS := $(subst $(TESTDIR),,$(PATHTS))

PATHUS := $(UT_SRC)unity.c
TSRCS += $(subst $(UT_SRC),,$(PATHUS))

TOBJS := $(patsubst %.c,%.o,$(TSRCS))
PATHTO := $(addprefix $(OBJDIR),$(TOBJS))

CFLAGS := -I$(INCDIR)
CFLAGS += -I$(UT_INC)

name := hello_world
program := $(BINDIR)hello_world
test := $(BINDIR)test_hello_world

.PHONY: all
all: $(program) $(test)
	@./build/bin/test_hello_world
	@./build/bin/hello_world

$(program): | $(BINDIR)

$(program): $(PATHO)
	$(CC) -o $@ $(PATHO)

$(PATHO): | $(OBJDIR)

$(PATHO): $(OBJDIR)%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


$(test): | $(BINDIR)

$(test): $(PATHTO) $(PATHOX)
	$(CC) -o $@ $(PATHTO) $(PATHOX)

$(PATHTO): | $(UT_LIB) $(OBJDIR)

$(PATHTO): $(UT_SRC)unity.c

$(PATHTO): $(OBJDIR)%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)


$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(UT_LIB):
	git clone https://github.com/ThrowTheSwitch/unity

.PHONY: clean
clean: clean$(UT_LIB)
	-rm $(OBJDIR)*.o && rmdir $(OBJDIR)
	-rm $(BINDIR)* && rmdir $(BINDIR)
	-rmdir build/

clean$(UT_LIB):
	-rm -rf $(UT_LIB)
