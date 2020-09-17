SHELL := /bin/sh
CC := gcc

INCDIR := inc/
SRCDIR := src/
OBJDIR := build/obj/
BINDIR := build/bin/
TESTDIR := test/

name := hello_world
program := $(BINDIR)hello_world
test := $(BINDIR)test_hello_world

vpath %.h $(INCDIR)
vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)
vpath %.c $(TESTDIR)

PATHS := $(wildcard $(SRCDIR)*.c)
SRCS := $(subst $(SRCDIR),,$(PATHS))
OBJS := $(patsubst %.c,%.o,$(SRCS))
PATHO := $(addprefix $(OBJDIR),$(OBJS))
PATHOX := $(filter-out $(OBJDIR)main.o,$(PATHO))

T_PATHS := $(wildcard $(TESTDIR)*.c)
T_SRCS := $(subst $(TESTDIR),,$(T_PATHS))
T_OBJS := $(patsubst %.c,%.o,$(T_SRCS))
T_PATHO := $(addprefix $(OBJDIR),$(T_OBJS))

CFLAGS := -I$(INCDIR)

.PHONY: all run
all: $(program) $(test) run

include unity.mk
CFLAGS += -I$(UT_PATHI)

run:
	@./build/bin/test_hello_world
	@./build/bin/hello_world

$(program): | $(BINDIR)

$(program): $(PATHO)
	$(CC) -o $@ $(PATHO)

$(PATHO): | $(OBJDIR)

$(PATHO): $(OBJDIR)%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(test): | $(BINDIR)

$(test): $(UT_OBJP) $(T_PATHO) $(PATHOX)
	$(CC) -o $@ $(T_PATHO) $(PATHOX) $(UT_OBJP)

$(T_PATHO): | $(OBJDIR)

$(T_PATHO): $(OBJDIR)%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

.PHONY: clean
clean: clean$(UT_LIB)
	-rm $(OBJDIR)*.o && rmdir $(OBJDIR)
	-rm $(BINDIR)* && rmdir $(BINDIR)
	-rmdir build/
