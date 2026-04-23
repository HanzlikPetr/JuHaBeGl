#Calculator - JuHaBeGl
#Petr Hanzlik (xhanzlp00)
.DEFAULT_GOAL := all

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -isystem googletest/googletest/include -pthread
DEPFLAGS = -MMD -MP

MATH_LIB_SRCS = $(wildcard ./math_lib/*.cpp)
TEST_SRCS = $(wildcard ./tests/*.cpp)
MATH_LIB_OBJS = $(MATH_LIB_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

GUI_SRC =  $(wildcard ./gui/*.cpp) $(wildcard ./gui/*.h) $(wildcard ./gui/*.ui) $(wildcard ./gui/*.qm)
GUI_DIR = ./gui/build

PROFILING_SRC= $(wildcard ./profiling/*.cpp)
PROFILING_OBJS = $(PROFILING_SRC:.cpp=.o)

ZIP_NAME = xhanzlp00_xjurokv00_xberanm00_xgleton00.zip

ALL_DEPS = $(MATH_LIB_OBJS:.o=.d) $(TEST_OBJS:.o=.d) $(PROFILING_OBJS:.o=.d)


TARGET_TEST = run_tests
TARGET_GUI = $(GUI_DIR)/gui_calculator

GTEST_DIR = googletest
GTEST_REPO = https://github.com/google/googletest.git
GTEST_VERSION = v1.14.0
GTEST_OBJS = gtest-all.o gtest_main.o



.PHONY: all test clean run stddev pack doc help

all: $(TARGET_TEST) $(TARGET_GUI) stddev

pack: clean
	cd .. && zip -r $(ZIP_NAME) .

clean:
	rm -f $(TARGET_TEST) $(MATH_LIB_OBJS) $(TEST_OBJS) $(ALL_DEPS) $(GTEST_OBJS) $(PROFILING_OBJS) ../$(ZIP_NAME) stddev
	rm -rf $(GTEST_DIR) $(GUI_DIR) html

test: $(TARGET_TEST)
	./$(TARGET_TEST)

doc:
	doxygen Doxyfile

run: $(TARGET_GUI)
	$(TARGET_GUI)

stddev: $(PROFILING_OBJS) $(MATH_LIB_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

help:
	@echo "======================================================================"
	@echo " NÁPOVĚDA K MAKEFILE / MAKEFILE HELP"
	@echo "======================================================================"
	@echo " Výchozí cíl (při spuštění 'make' bez parametrů) je 'make all'."
	@echo " Default target (when running 'make' without arguments) is 'make all'."
	@echo "----------------------------------------------------------------------"
	@echo " [CZ] POSTUP PRO KOMPILACI NA VIRTUÁLNÍM STROJI:"
	@echo "  1. Otevřete terminál a přejděte do složky s Makefile."
	@echo "  2. Spusťte příkaz 'make' pro stažení závislostí a kompletní překlad."
	@echo ""
	@echo " DOSTUPNÉ CÍLE:"
	@echo "  make all    - Přeloží projekt (vč. programu pro profiling) a stáhne závislosti."
	@echo "  make pack   - Zabalí projekt tak, aby mohl být odevzdán."
	@echo "  make clean  - Smaže všechny soubory, co nemají být odevzdány."
	@echo "  make test   - Spustí testy matematické knihovny."
	@echo "  make doc    - Spustí generování programové dokumentace."
	@echo "  make run    - Spustí přeložený program."
	@echo "  make stddev - Přeloží program pro výpočet směr. odchylky na profiling."
	@echo "  make help   - Vypíše tuto nápovědu."
	@echo "----------------------------------------------------------------------"
	@echo " [EN] COMPILATION PROCESS ON A VIRTUAL MACHINE:"
	@echo "  1. Open a terminal and navigate to the directory containing Makefile."
	@echo "  2. Run 'make' to download dependencies and fully build the project."
	@echo ""
	@echo " AVAILABLE TARGETS:"
	@echo "  make all    - Compiles the project (incl. profiling program) & gets dependencies."
	@echo "  make pack   - Packages the project so it is ready for submission."
	@echo "  make clean  - Deletes all files that should not be submitted."
	@echo "  make test   - Runs tests for the mathematical library."
	@echo "  make doc    - Generates the programming documentation."
	@echo "  make run    - Executes the compiled program."
	@echo "  make stddev - Compiles the standard deviation program for profiling."
	@echo "  make help   - Displays this help message."
	@echo "======================================================================"

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

$(TEST_OBJS): | $(GTEST_DIR)

$(TARGET_GUI): $(GUI_SRC) | $(GUI_DIR)
	@if [ ! -f $(GUI_DIR)/Makefile ]; then \
		echo "Spoustim CMake..."; \
		cd $(GUI_DIR) && cmake ..; \
	fi
	cp ./gui/kalkulacka_cs.qm $(GUI_DIR)/kalkulacka_cs.qm;
	$(MAKE) -C $(GUI_DIR)

# Pattern rule to compile .cpp files into .o files, generating dependency files as well
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(ALL_DEPS)
