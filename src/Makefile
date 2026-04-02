#Calculator - JuHaBeGl
#Petr Hanzlik (xhanzlp00)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -isystem googletest/googletest/include -pthread
DEPFLAGS = -MMD -MP

MATH_LIB_SRCS = $(wildcard ./math_lib/*.cpp)
TEST_SRCS = $(wildcard ./tests/*.cpp)
MATH_LIB_OBJS = $(MATH_LIB_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

GUI_SRC =  $(wildcard ./gui/*.cpp) $(wildcard ./gui/*.h) $(wildcard ./gui/*.ui)
GUI_DIR = ./gui/build

ALL_DEPS = $(MATH_LIB_OBJS:.o=.d) $(TEST_OBJS:.o=.d)


TARGET_TEST = run_tests
TARGET_GUI = $(GUI_DIR)/gui_calculator

GTEST_DIR = googletest
GTEST_REPO = https://github.com/google/googletest.git
GTEST_VERSION = v1.14.0
GTEST_OBJS = gtest-all.o gtest_main.o



.PHONY: all test clean run

all: $(TARGET_TEST) $(TARGET_GUI)

test: $(TARGET_TEST)
	./$(TARGET_TEST)

run: $(TARGET_GUI)
	$(TARGET_GUI)

# Test target depends on math library objects, test objects, and Google Test objects
$(TARGET_TEST): $(MATH_LIB_OBJS) $(TEST_OBJS) $(GTEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(GTEST_DIR):
	@if [ ! -d "$@" ]; then \
		echo "Dir $@ does not exist. Cloning Google Test..."; \
		git clone --depth 1 -b $(GTEST_VERSION) -q $(GTEST_REPO) $@; \
	else \
		echo "Dir $@ already exists. Skipping download."; \
	fi

gtest-all.o: | $(GTEST_DIR)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/googletest -c $(GTEST_DIR)/googletest/src/gtest-all.cc -o $@

gtest_main.o: | $(GTEST_DIR)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/googletest -c $(GTEST_DIR)/googletest/src/gtest_main.cc -o $@

# GUI target depends on all GUI source files and the GUI build directory
$(GUI_DIR):
	@if [ ! -d "$@" ]; then \
		mkdir $@; \
	fi

$(TARGET_GUI): $(GUI_SRC) | $(GUI_DIR)
	@if [ ! -f $(GUI_DIR)/Makefile ]; then \
		echo "Spoustim CMake..."; \
		cd $(GUI_DIR) && cmake ..; \
	fi
	$(MAKE) -C $(GUI_DIR)

# Pattern rule to compile .cpp files into .o files, generating dependency files as well
%.o: %.cpp | $(GTEST_DIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET_TEST) $(MATH_LIB_OBJS) $(TEST_OBJS) $(ALL_DEPS) $(GTEST_OBJS)
	rm -rf $(GTEST_DIR) $(GUI_DIR)

-include $(ALL_DEPS)
