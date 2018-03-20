include Makefile.defs

PRIMARY_TARGET = go
TARGETS = $(PRIMARY_TARGET)

all: $(TARGETS)

SRCS = \
		 main.cpp \
		 raii_socket.cpp \

# TODO: automate this, generate deps files, etc
raii_socket.cpp: raii_socket.h
main.cpp: raii_socket.h

OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(OBJS:%.o=%.o.d)
TARGETS += $(DEPS) $(OBJS) 

-include $(DEPS)

$(PRIMARY_TARGET): $(OBJS) | $(DEPS) 
	@echo Linking $@
	@$(LINK)

.PHONY: test
test:
	$(MAKE) -C test
	test/all_tests

.PHONY: clean
clean:
	-rm -rf $(OBJS) $(TARGETS)

