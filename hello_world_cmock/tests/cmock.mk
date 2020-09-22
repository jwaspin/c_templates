CMOCK_LIB   := cmock
CMOCK_BUILD := tts/
CMOCK_PATH  := $(CMOCK_BUILD)cmock/
CMOCK_PATHI := $(CMOCK_PATH)src/
CMOCK_PATHS := $(CMOCK_PATH)src/
CMOCK_PATHO := $(CMOCK_BUILD)obj/

CMOCK_PATHL := $(CMOCK_PATH)lib/
CMOCK_RUBY := $(CMOCK_PATHL)cmock.rb

CMOCK_SRC  := cmock.c
CMOCK_SRCP := $(CMOCK_PATHS)$(CMOCK_SRC)
CMOCK_OBJ  := cmock.o
CMOCK_OBJP := $(CMOCK_PATHO)$(CMOCK_OBJ)

CMOCK_CFLAGS := -I$(CMOCK_PATHI)
CMOCK_CFLAGS += -I$(UNITY_PATHI)

vpath %.h $(CMOCK_PATHI)
vpath %.c $(CMOCK_PATHS)
vpath %.o $(CMOCK_PATHO)

MOCKS_PATH  := mocks/
MOCKS_SRCSP := $(wildcard $(MOCKS_PATH)*.c)
MOCKS_SRCS  := $(notdir $(MOCKS_SRCSP))
MOCKS_OBJS  := $(patsubst %.c,%.o,$(MOCKS_SRCS))
MOCKS_OBJSP := $(addprefix $(PATHO),$(MOCKS_OBJS))

MOCKS_CFLAGS := $(CMOCK_CFLAGS)
MOCKS_CFLAGS += -I$(MOCKS_PATH)
MOCKS_CFLAGS += -I$(PATHI)

vpath %.h $(MOCKS_PATH)
vpath %.c $(MOCKS_PATH)

.PHONY: $(CMOCK_LIB)
$(CMOCK_LIB): $(CMOCK_OBJP) mocks

$(CMOCK_OBJP): | $(UNITY_LIB) $(CMOCK_PATH) $(CMOCK_PATHO)

$(CMOCK_OBJP): $(CMOCK_SRCP)

$(CMOCK_OBJP):
	$(CC) -o $@ -c $< $(CMOCK_CFLAGS)	

$(CMOCK_PATH):
	git clone --recursive \
			https://github.com/throwtheswitch/cmock.git $(CMOCK_PATH)
	cd $(CMOCK_PATH) && bundle install
	@echo "cmock installed successfully"

mocks:
	ruby $(CMOCK_RUBY) $(PATHI)*.h

$(MOCKS_OBJSP): | mocks

$(MOCKS_OBJSP): $(PATHO)%.o: %.c
	$(CC) -o $@ -c $< $(MOCKS_CFLAGS)	

.PHONY: clean$(CMOCK_LIB) cleanmocks
clean$(CMOCK_LIB): cleanmocks
	-rm -rf $(CMOCK_PATH)
	-rm -rf $(CMOCK_PATHO)
	-rmdir $(CMOCK_BUILD)

cleanmocks:
	-rm -rf $(MOCKS_PATH)
