# A line starting with a has is a comment, we'll build up
# the below example

TARGET = AXC
SRC_FILES = main.cpp BinarySearchTree.hpp

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++
CXXFLAGS_DEBUG = -g
CXXFLAGS_WARN = -Wall -Wextra -Wunreachable-code -Wshadow -Wpedantic
CPPVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
	Q=
else
	DEL = rm -f
	Q="
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CPPVERSION) $(CXXFLAGS_DEBUG) $(CXXFLAGS_WARN) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS) Makefile.bak

depend:
	@sed -i.bak '/^# DEPENDENCIES/,$$d' Makefile
	@$(DEL) sed*
	@echo $(Q)# DEPENDENCIES$(Q) >> Makefile
	@$(CXX) -MM $(SRC_FILES) >> Makefile

.PHONY: all clean depend

# DEPENDENCIES
main.o: main.cpp BinarySearchTree.hpp
BinarySearchTree.o: BinarySearchTree.hpp
