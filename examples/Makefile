ALLEXAMPLES=$(filter-out Makefile,$(wildcard *))
TARGETS=$(foreach dir,$(ALLEXAMPLES),$(dir)/$(dir))

# A recipe for making an example inside folder with the same name
define EXAMPLE_rule
$(1)/$(1): $(wildcard $(1)/*.cpp)
	$(MAKE) -C $(1)
endef
	
all: $(TARGETS)

$(foreach folder,$(ALLEXAMPLES),$(eval $(call EXAMPLE_rule,$(folder))))
		

