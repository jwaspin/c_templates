UT_LIB := unity
UT_PATHI := unity/src/
UT_PATHS := unity/src/
UT_PATHB := build/
UT_PATHO := build/unity/

UT_SRC := unity.c
UT_SRCP := $(UT_PATHS)$(UT_SRC)
UT_OBJ := unity.o
UT_OBJP := $(UT_PATHO)$(UT_OBJ)

vpath %.h $(UT_PATHI)
vpath %.c $(UT_PATHS)
vpath %.o $(UT_PATHO)

$(UT_OBJP): | $(UT_LIB) $(UT_PATHO)

$(UT_OBJP): $(UT_SRCP)

$(UT_OBJP):
	$(CC) -o $@ -c $< $(CFLAGS)	

$(UT_LIB):
	git clone https://github.com/ThrowTheSwitch/unity

$(UT_PATHO):
	-mkdir -p $(UT_PATHO)

.PHONY: clean$(UT_LIB)
clean$(UT_LIB):
	-rm -rf $(UT_LIB)
	-rm -rf $(UT_PATHO)
