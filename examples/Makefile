ALLEXAMPLES=$(filter-out Makefile,$(wildcard *))
TARGETS=$(foreach dir,$(ALLEXAMPLES),$(dir)/$(dir))

all: $(TARGETS)
	
%/scribble:  $(wildcard $(lastword $(subst /, ,$@))/*.cpp)
	@echo making $@
	$(MAKE) -C $(lastword $(subst /, ,$@))

%/ellipse:  $(wildcard $(lastword $(subst /, ,$@))/*.cpp)
	@echo making $@
	$(MAKE) -C $(lastword $(subst /, ,$@))

