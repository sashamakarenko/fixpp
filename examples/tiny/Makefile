PRJ_NAME    := tiny
PRJ_BRANCH  := 1.0
PRJ_VERSION := $(PRJ_BRANCH).0
PRJ_TYPE    := lib

include ../../../makefile/Makefile

ifneq ($(MAKECMDGOALS),clean)
-include build/fixgenerated.mk
endif

build/fixgenerated.mk: src/$(PRJ_NAME)/FixApi.h
	$(V)mkdir -p $(@D)
	$(V)touch $@

src/$(PRJ_NAME)/FixApi.h: $(wildcard src/spec/*.def)
	$(V)../../generate.sh --clean-fields -d $$PWD/src/$(PRJ_NAME) -s $$PWD/src/spec -i $(PRJ_NAME) -n $(PRJ_NAME) -p $$PWD/src/gdb

clean::
	$(V)rm -rf src/gdb src/$(PRJ_NAME) mdfr.html
