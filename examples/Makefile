
DIRS := tiny odd fix44 fixdump

all: $(foreach d,$(DIRS),build-$(d))

clean: $(foreach d,$(DIRS),clean-$(d))

check: $(foreach d,$(DIRS),check-$(d))

build-%:
	@echo "Building $*"
	@$(MAKE) --no-print-directory -C $*

check-%:
	@echo "Cleaning $*"
	@$(MAKE) --no-print-directory -C $* check

clean-%:
	@echo "Cleaning $*"
	@$(MAKE) --no-print-directory -C $* clean
