include ../Makefile.defs

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = $(ENV_HOME)/gmock-1.7.0/gtest
GMOCK_DIR = $(ENV_HOME)/gmock-1.7.0

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
GMOCK_SRCS_ = $(GMOCK_DIR)/src/*.cc $(GMOCK_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -isystem $(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gmock-all.o : $(GMOCK_SRCS_)
	$(CXX) $(CPPFLAGS) -isystem $(GMOCK_DIR) $(CXXFLAGS) -c \
            $(GMOCK_DIR)/src/gmock-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -isystem $(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gmock-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^
	
# The GTEST macros cause these warnings to be thrown; I'm disabling them for now.
CXXFLAGS += -Wno-global-constructors

# A test should link with either gtest.a or gtest_main.a, depending on whether
# it defines its own main() function.

PRIMARY_TARGET = all_tests
TARGETS = $(PRIMARY_TARGET)

all: $(TARGETS)

SRCS = \
		 raii_socket_test.cpp \

OBJS = $(SRCS:%.cpp=%.o)

CPPFLAGS += -I ..
CPPFLAGS += -isystem $(GTEST_DIR)/include
CPPFLAGS += -isystem $(GMOCK_DIR)/include

TEST_SUBJECT_OBJS = \
						  ../raii_socket.o \


$(PRIMARY_TARGET): $(TEST_SUBJECT_OBJS) $(OBJS) gtest_main.a
	$(CXX) $(LDFLAGS) $+ $(LDLIBS) -o $@

.PHONY: clean
clean:
	-rm -rf $(OBJS) $(TARGETS)

