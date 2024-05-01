PRJ_NAME    := fix44
PRJ_BRANCH  := 1.0
PRJ_VERSION := $(PRJ_BRANCH).0
PRJ_TYPE    := lib

CPP_EXTRA_FLAGS = -Wall -Wextra -Wno-unused-parameter -Werror -fmax-errors=1 #-Wpedantic

-include ../../../makefile/Makefile

../../../makefile/Makefile:
	@echo "cloning makefile..."
	@cd ../../..; git clone https://github.com/sashamakarenko/makefile.git makefile

ifneq ($(MAKECMDGOALS),clean)
-include build/fixgenerated.mk

build/fixgenerated.mk: src/$(PRJ_NAME)/FixApi.h
	$(V)mkdir -p $(@D)
	$(V)touch $@

src/$(PRJ_NAME)/FixApi.h: $(wildcard ../spec/fix44/*.def) $(wildcard ../../src/*.h) $(wildcard ../../src/*.cpp) $(wildcard ../../src/*.pp) ../../generate.sh
	$(V)../../generate.sh -d $$PWD/src/$(PRJ_NAME) -s $$PWD/../spec/fix44 -i $(PRJ_NAME) -n $(PRJ_NAME) -p $$PWD/src/gdb

endif

clean-generated::
	$(V)rm -rf src/$(PRJ_NAME)

clean::
	$(V)rm -rf src/gdb
