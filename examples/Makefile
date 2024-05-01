DIRS := tiny odd fix44 fixdump order
RULES := all clean check recheck
deps = $(foreach d,$(DIRS),$(1)-$(d))

.NOTPARALLEL:

$(foreach r,$(RULES),$(eval $(r): $(call deps,$(r))))

$(foreach r,$(RULES),$(r)-%):
	@$(MAKE) --no-print-directory -C $* $(@:-$*=)

