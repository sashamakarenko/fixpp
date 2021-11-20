PRJ_NAME    := fix44
PRJ_BRANCH  := 1.0
PRJ_VERSION := $(PRJ_BRANCH).0
PRJ_TYPE    := lib

TARGET_EXTRA_DEPENDENCY = src/$(PRJ_NAME)/FixApi.h

include ../../../makefile/Makefile

ifneq ($(MAKECMDGOALS),clean)
-include build/fixgenerated.mk

build/fixgenerated.mk: src/$(PRJ_NAME)/FixApi.h
	$(V)mkdir -p $(@D)
	$(V)touch $@

src/$(PRJ_NAME)/FixApi.h: $(wildcard ../spec/fix44/*.def) $(wildcard ../../src/*.h) $(wildcard ../../src/*.cpp) $(wildcard ../../src/*.pp) ../../generate.sh
	$(V)../../generate.sh -d $$PWD/src/$(PRJ_NAME) -s $$PWD/../spec/fix44 -i $(PRJ_NAME) -n $(PRJ_NAME) -p $$PWD/src/gdb

endif

clean::
	$(V)rm -rf src/gdb
