PRJ_NAME    := tiny
PRJ_BRANCH  := 1.0
PRJ_VERSION := $(PRJ_BRANCH).0
PRJ_TYPE    := lib

DEV_ROOT   := ../../..
FIXPP_DIR  := ../..

PE_PRJ_DIR := $(DEV_ROOT)/pe
ifneq ($(wildcard $(PE_PRJ_DIR)),)
    TestPerf_EXTRA_CPP_FLAGS           := -I$(PE_PRJ_DIR)/src
    TestPerf_EXTRA_LD_PATH             := $(PE_PRJ_DIR)/build/lib/release
    TestPerf_EXTRA_LINK_FLAGS          := -L$(TestPerf_EXTRA_LD_PATH) -lpe-1.0
    TestPerf_EXTRA_DEPENDENCY          := $(PE_PRJ_DIR)/build/lib/release/libpe-1.0.so
    TestPerf_EXTRA_LAUNCHER            := LD_PRELOAD=$(PE_PRJ_DIR)/build/lib/release/libPePreload-1.0.so
    TestSenderPerf_EXTRA_CPP_FLAGS     := $(TestPerf_EXTRA_CPP_FLAGS)
    TestSenderPerf_EXTRA_LD_PATH       := $(TestPerf_EXTRA_LD_PATH)
    TestSenderPerf_EXTRA_LINK_FLAGS    := $(TestPerf_EXTRA_LINK_FLAGS)
    TestSenderPerf_EXTRA_DEPENDENCY    := $(TestPerf_EXTRA_DEPENDENCY)
    TestSenderPerf_EXTRA_LAUNCHER      := LD_PRELOAD=$(PE_PRJ_DIR)/build/lib/release/libPePreload-1.0.so
    TestSendForexPerf_EXTRA_CPP_FLAGS  := $(TestPerf_EXTRA_CPP_FLAGS)
    TestSendForexPerf_EXTRA_LD_PATH    := $(TestPerf_EXTRA_LD_PATH)
    TestSendForexPerf_EXTRA_LINK_FLAGS := $(TestPerf_EXTRA_LINK_FLAGS)
    TestSendForexPerf_EXTRA_DEPENDENCY := $(TestPerf_EXTRA_DEPENDENCY)
else
    ifneq ($(findstring test-,$(MAKECMDGOALS))$(findstring check,$(MAKECMDGOALS)),)
        $(warning TestPerf and TestSenderPerf are disabled: visit https://github.com/sashamakarenko/pe)
        $(warning Next to fixpp: git clone https://github.com/sashamakarenko/pe.git pe)
    endif
    DISABLED_TESTS = Perf SenderPerf SendForexPerf
endif

TEST_DEFINES = -DEXIT_ON_ERROR
CPP_EXTRA_FLAGS = -Wall -Wextra -Wno-unused-parameter -Werror -fmax-errors=1 #-Wpedantic

-include $(DEV_ROOT)/makefile/Makefile

$(DEV_ROOT)/makefile/Makefile:
	@echo "cloning makefile..."
	@cd $(DEV_ROOT); git clone https://github.com/sashamakarenko/makefile.git makefile

ifneq ($(MAKECMDGOALS),clean)
-include build/fixgenerated.mk

build/fixgenerated.mk: src/$(PRJ_NAME)/FixApi.h
	$(V)mkdir -p $(@D)
	$(V)touch $@

OUTBOUND_MESAGES=LOGON NEW_ORDER_SINGLE

generate: build/fixgenerated.mk

src/$(PRJ_NAME)/FixApi.h: $(wildcard src/spec/*.def) $(wildcard $(FIXPP_DIR)/src/*.*) $(FIXPP_DIR)/generate.sh
	$(V)$(FIXPP_DIR)/generate.sh --clean-fields -d $$PWD/src/$(PRJ_NAME) -s $$PWD/src/spec -i $(PRJ_NAME) -n $(PRJ_NAME) -p $$PWD/src/gdb
	$(V)for mt in _ $(OUTBOUND_MESAGES); do sed "/case-begin-$$mt/,/case-end-$$mt/d" -i src/$(PRJ_NAME)/Messages.cpp; done

endif

$(TestPerf_EXTRA_DEPENDENCY):
	$(REMAKE) -C $(PE_PRJ_DIR)

clean::
	$(V)rm -rf src/gdb src/$(PRJ_NAME) mdfr.html
