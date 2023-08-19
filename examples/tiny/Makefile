PRJ_NAME    := tiny
PRJ_BRANCH  := 1.0
PRJ_VERSION := $(PRJ_BRANCH).0
PRJ_TYPE    := lib

PE_PRJ_DIR := ../../../pe
ifneq ($(wildcard $(PE_PRJ_DIR)),)
    TestPerf_EXTRA_CPP_FLAGS           := -I$(PE_PRJ_DIR)/src
    TestPerf_EXTRA_LD_PATH             := $(PE_PRJ_DIR)/build/lib/release
    TestPerf_EXTRA_LINK_FLAGS          := -L$(TestPerf_EXTRA_LD_PATH) -lpe-1.0
    TestPerf_EXTRA_DEPENDENCY          := $(PE_PRJ_DIR)/build/lib/release/libpe-1.0.so
    TestSenderPerf_EXTRA_CPP_FLAGS     := $(TestPerf_EXTRA_CPP_FLAGS)
    TestSenderPerf_EXTRA_LD_PATH       := $(TestPerf_EXTRA_LD_PATH)
    TestSenderPerf_EXTRA_LINK_FLAGS    := $(TestPerf_EXTRA_LINK_FLAGS)
    TestSenderPerf_EXTRA_DEPENDENCY    := $(TestPerf_EXTRA_DEPENDENCY)
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

# CPP_EXTRA_FLAGS = -flto

-include ../../../makefile/Makefile

../../../makefile/Makefile:
	@echo "cloning makefile..."
	@cd ../../..; git clone https://github.com/sashamakarenko/makefile.git makefile

ifneq ($(MAKECMDGOALS),clean)
-include build/fixgenerated.mk

build/fixgenerated.mk: src/$(PRJ_NAME)/FixApi.h
	$(V)mkdir -p $(@D)
	$(V)touch $@

OUTBOUND_MESAGES=LOGON ORDER_SINGLE

src/$(PRJ_NAME)/FixApi.h: $(wildcard src/spec/*.def) $(wildcard ../../src/*.h) $(wildcard ../../src/*.cpp) $(wildcard ../../src/*.pp) ../../generate.sh
	$(V)../../generate.sh --clean-fields -d $$PWD/src/$(PRJ_NAME) -s $$PWD/src/spec -i $(PRJ_NAME) -n $(PRJ_NAME) -p $$PWD/src/gdb
	$(V)for mt in _ $(OUTBOUND_MESAGES); do sed "/case-begin-$$mt/,/case-end-$$mt/d" -i src/$(PRJ_NAME)/Messages.cpp; done

endif

$(TestPerf_EXTRA_DEPENDENCY):
	$(SUBMAKE) -C $(PE_PRJ_DIR)

clean::
	$(V)rm -rf src/gdb src/$(PRJ_NAME) mdfr.html
