# Compiler
CXX = cl
CXXFLAGS = /std:c++17 /W4

# List of programs (each program is linked from main.o + <prog>.o)
PROGRAMS = multiply

all: $(PROGRAMS)

# Link rule: build an executable by linking main.o and <prog>.o
# Note: Makefiles require a TAB at the start of recipe lines. Keep tabs.
%: main.o %.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAMS) *.o

.PHONY: all clean $(PROGRAMS)