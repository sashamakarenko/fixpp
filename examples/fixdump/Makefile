PRJ_NAME    := fixdump
PRJ_BRANCH  := 1.0
PRJ_VERSION := $(PRJ_BRANCH).0
PRJ_TYPE    := exe

SRCSUBDIRS := fix42 fix44

-include ../../../makefile/Makefile

../../../makefile/Makefile:
	@echo "cloning makefile..."
	@cd ../../..; git clone https://github.com/sashamakarenko/makefile.git makefile

ifneq ($(MAKECMDGOALS),clean)
-include build/fixgenerated.mk
endif

test: $(TARGET)
	$(V)$(SUBMAKE) go ARGS="8=FIX.4.89=0 bad 8=FIX.4.49=31535=W49=foo56=bar34=123452=20190101-01:01:01.00055=EUR/USD268=6269=1290=1270=1.2115=USD271=1000000269=1290=2270=1.21115=USD271=2000000269=1290=3270=1.22115=USD271=3000000269=1290=4270=1.231515=USD271=4000000269=0290=5270=1.20115=USD271=1000000269=0290=6270=1.20515=USD271=200000010=173 8=FIX.4.29=31535=W49=foo56=bar34=123452=20190101-01:01:01.00055=EUR/USD268=6269=1290=1270=1.2115=USD271=1000000269=1290=2270=1.21115=USD271=2000000269=1290=3270=1.22115=USD271=3000000269=1290=4270=1.231515=USD271=4000000269=0290=5270=1.20115=USD271=1000000269=0290=6270=1.20515=USD271=200000010=173"

build/fixgenerated.mk: $(foreach d,$(SRCSUBDIRS),src/$(PRJ_NAME)/$d/FixApi.h)
	$(V)mkdir -p $(@D)
	$(V)touch $@


src/$(PRJ_NAME)/%/FixApi.h: FIX_VERSION = $*
src/$(PRJ_NAME)/%/FixApi.h: $(wildcard ../spec/%/*.def)
	$(V)../../../fixpp/generate.sh -d $$PWD/src/$(PRJ_NAME)/$(FIX_VERSION) -s $$PWD/../spec/$(FIX_VERSION) -i $(PRJ_NAME)/$(FIX_VERSION) -n $(PRJ_NAME)::$(FIX_VERSION)  -p $$PWD/src/gdb
	$(V)sed "s/ fixppGetEnumName/ $(FIX_VERSION)_fixppGetEnumName/" -i src/$(PRJ_NAME)/$(FIX_VERSION)/Messages.cpp

clean::
	$(V)rm -rf $(foreach d,$(SRCSUBDIRS),src/$(PRJ_NAME)/$d) src/gdb/
