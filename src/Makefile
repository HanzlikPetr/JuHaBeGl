#Calculator - JuHaBeGl
#Petr Hanzlik (xhanzlp00)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
DEPFLAGS = -MMD -MP

MATH_LIB_SRCS = $(wildcard ./math_lib/*.cpp)
TEST_SRCS = $(wildcard ./tests/*.cpp)

MATH_LIB_OBJS = $(MATH_LIB_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

ALL_DEPS = $(MATH_LIB_OBJS:.o=.d) $(TEST_OBJS:.o=.d)

TARGET_TEST = run_tests

.PHONY: all test clean

all: $(TARGET_TEST)

test: $(TARGET_TEST)
	./$(TARGET_TEST)


$(TARGET_TEST): $(MATH_LIB_OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lgtest -lgtest_main -pthread

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET_TEST) $(MATH_LIB_OBJS) $(TEST_OBJS) $(ALL_DEPS)

-include $(ALL_DEPS)
