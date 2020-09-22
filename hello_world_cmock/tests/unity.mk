UNITY_LIB   := unity
UNITY_BUILD := tts/
UNITY_PATH  := $(UNITY_BUILD)unity/
UNITY_PATHI := $(UNITY_PATH)src/
UNITY_PATHS := $(UNITY_PATH)src/
UNITY_PATHO := $(UNITY_BUILD)obj/

UNITY_SRC  := unity.c
UNITY_SRCP := $(UNITY_PATHS)$(UNITY_SRC)
UNITY_OBJ  := unity.o
UNITY_OBJP := $(UNITY_PATHO)$(UNITY_OBJ)

UNITY_CFLAGS := -I$(UNITY_PATHI)

vpath %.h $(UNITY_PATHI)
vpath %.c $(UNITY_PATHS)
vpath %.o $(UNITY_PATHO)

.PHONY: $(UNITY_LIB)
$(UNITY_LIB): $(UNITY_OBJP)

$(UNITY_OBJP): | $(UNITY_PATH) $(UNITY_PATHO)

$(UNITY_OBJP): $(UNITY_SRCP)

$(UNITY_OBJP):
	$(CC) -o $@ -c $< $(UNITY_CFLAGS)	

$(UNITY_PATH):
	git clone https://github.com/ThrowTheSwitch/unity $(UNITY_PATH)

$(UNITY_PATHO):
	mkdir -p $(UNITY_PATHO)

.PHONY: clean$(UNITY_LIB)
clean$(UNITY_LIB):
	-rm -rf $(UNITY_PATH)
	-rm -rf $(UNITY_PATHO)
	-rmdir $(UNITY_BUILD)
