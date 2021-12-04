PRJ_NAME    := odd
PRJ_BRANCH  := 1.0
PRJ_VERSION := $(PRJ_BRANCH).0
PRJ_TYPE    := lib

-include ../../../makefile/Makefile

../../../makefile/Makefile:
	@echo "cloning makefile..."
	@cd ../../..; git clone https://github.com/sashamakarenko/makefile.git makefile

ifneq ($(MAKECMDGOALS),clean)
-include build/fixgenerated.mk
endif

build/fixgenerated.mk: src/$(PRJ_NAME)/FixApi.h
	$(V)mkdir -p $(@D)
	$(V)touch $@

src/$(PRJ_NAME)/FixApi.h: $(wildcard src/spec/*.def)
	$(V)../../../fixpp/generate.sh --clean-fields -d $$PWD/src/$(PRJ_NAME) -s $$PWD/src/spec -i $(PRJ_NAME) -n $(PRJ_NAME) -p $$PWD/src/gdb

clean::
	$(V)rm -rf src/gdb src/$(PRJ_NAME)

