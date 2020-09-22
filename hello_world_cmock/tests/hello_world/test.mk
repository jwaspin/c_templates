UNIT_NAME  := hello_world
UNIT_OBJ   := $(UNIT_NAME).o
UNIT_OBJP  := $(addprefix $(PATHO),$(UNIT_OBJ))

LOCAL_PATH := $(PATHT)$(UNIT_NAME)/
LOCAL_SRC  := test_$(UNIT_NAME).c
LOCAL_SRCP := $(LOCAL_PATH)$(LOCAL_SRC)
LOCAL_OBJ  := test_$(UNIT_NAME).o
LOCAL_OBJP := $(PATHO)$(LOCAL_OBJ)
LOCAL_BIN  := $(PATHB)test_$(UNIT_NAME)

vpath %.c $(LOCAL_PATH)

TST_SRCS  += $(LOCAL_SRC)
TST_SRCSP += $(LOCAL_SRCP)

LOCAL_MOCKS := hello
LOCAL_MOCKS += world
LOCAL_MOCKS_OBJS := $(addprefix $(PATHO)Mock, \
					$(addsuffix .o,$(LOCAL_MOCKS)))

LOCAL_DEPS := $(LOCAL_OBJP)
LOCAL_DEPS += $(LOCAL_MOCKS_OBJS)
LOCAL_DEPS += $(UNIT_OBJP)
LOCAL_DEPS += $(UNITY_OBJP)
LOCAL_DEPS += $(CMOCK_OBJP)

$(LOCAL_BIN): $(LOCAL_DEPS)
	echo $(LOCAL_BIN) $(LOCAL_DEPS)
	$(CC) -o $@ $^
