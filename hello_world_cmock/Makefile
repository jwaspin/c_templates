NAME := hello_world

SHELL := /bin/sh
CC    := gcc

# Source and header directories
PATHI := inc/
PATHS := src/
PATHT := tests/

# Build directories
BUILD := build/
PATHO := $(BUILD)obj/
PATHB := $(BUILD)bin/

PROGRAM := $(PATHB)$(NAME)

SRCSP := $(wildcard $(PATHS)*.c)
SRCS  := $(notdir $(SRCSP))
SRCSB := $(basename $(SRCS))
OBJS  := $(addsuffix .o,$(SRCSB))
OBJSP := $(addprefix $(PATHO),$(OBJS))

TST_SRCSB := $(filter-out main,$(SRCSB))
TST_MK    := $(addsuffix /test.mk, \
		$(addprefix $(PATHT),$(TST_SRCSB)))
TST_SRCS  := 
TST_SRCSP :=

vpath %.h $(PATHI)
vpath %.c $(PATHS)
vpath %.o $(PATHO)

CFLAGS := -I$(PATHI)

.PHONY: all
all: $(PROGRAM) test run

UT_LIB := unity
MOCK_LIB := cmock

include $(PATHT)$(UT_LIB).mk
include $(PATHT)$(MOCK_LIB).mk
include $(TST_MK)

TST_OBJS  := $(patsubst %.c,%.o,$(TST_SRCS))
TST_OBJSP := $(addprefix $(PATHO),$(TST_OBJS))
TST_BIN   := $(addprefix $(PATHB),$(basename $(TST_SRCS)))

TST_CFLAGS := $(CFLAGS)
TST_CFLAGS += -I$(UNITY_CFLAGS)
TST_CFLAGS += -I$(CMOCK_CFLAGS)
TST_CFLAGS += -I$(MOCKS_PATH)

$(PROGRAM): | $(PATHB)

$(PROGRAM): $(OBJSP)
	$(CC) -o $@ $(OBJSP)

$(OBJSP): | $(PATHO)

$(OBJSP): $(PATHO)%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: runprogram
runprogram:
	@echo "\n.........................Running $(PROGRAM)................................................\n" | cut -c -80
	@./$(PROGRAM)
	@echo "\n................................................................................\n"

.PHONY: test
test: $(UT_LIB) $(MOCK_LIB) $(TST_OBJSP) $(MOCKS_OBJS) $(TST_BIN)

$(TST_OBJSP): | $(PATHO)

$(TST_OBJSP): $(PATHO)%.o: %.c
	$(CC) -o $@ -c $< $(TST_CFLAGS)

.PHONY: runtest
runtest: $(TST_BIN)
	@echo "\n\n.........................Running tests..........................................\n\n"
	@for test in $(TST_BIN) ; do \
		./$$test ; \
		echo ; \
	done
	@echo "................................................................................"

.PHONY: run
run: runtest runprogram

.PHONY: clean cleanobj cleanbin
clean: clean$(UT_LIB) clean$(MOCK_LIB)
	-rm -rf $(BUILD)

cleanobj:
	-rm -rf $(PATHO)

cleanbin:
	-rm -rf $(PATHB)

$(PATHB): | $(BUILD)
	mkdir -p $(PATHB)

$(PATHO): | $(BUILD)
	mkdir -p $(PATHO)

$(BUILD):
	mkdir $(BUILD)
