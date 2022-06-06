PRJ_NAME    := order
PRJ_BRANCH  := 1.0
PRJ_VERSION := $(PRJ_BRANCH).0
PRJ_TYPE    := lib


-include ../../../makefile/Makefile

../../../makefile/Makefile:
	@echo "cloning makefile..."
	@cd ../../..; git clone https://github.com/sashamakarenko/makefile.git makefile

ifneq ($(MAKECMDGOALS),clean-all)
-include build/fixgenerated.mk

build/fixgenerated.mk: src/$(PRJ_NAME)/FixApi.h
	$(V)mkdir -p $(@D)
	$(V)touch $@

src/$(PRJ_NAME)/FixApi.h: $(wildcard src/spec/*.def)
	$(V)../../generate.sh --clean-fields -d $$PWD/src/$(PRJ_NAME) -s $$PWD/src/spec -i $(PRJ_NAME) -n $(PRJ_NAME) -p $$PWD/src/gdb

endif

clean-all: clean
	$(V)rm -rf src/gdb src/$(PRJ_NAME) build/fixgenerated.mk
