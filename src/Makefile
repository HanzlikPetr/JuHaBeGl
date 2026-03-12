#Calculator - JuHaBeGl
#Petr Hanzlik (xhanzlp00)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TEST_FILES = $(wildcard *test.cpp)

test: $(TEST_FILES) math_lib.cpp math_lib.h
	$(CXX) $(CXXFLAGS) $(TEST_FILES) math_lib.cpp -o run_tests -lgtest -lgtest_main -pthread
	./run_tests
