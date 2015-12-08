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

$(PRIMARY_TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(LDLIBS) $+ -o $@

.PHONY: clean
clean:
	-rm -rf $(OBJS) $(TARGETS)

