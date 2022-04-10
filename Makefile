# HAYAT Rahim - MAKEFILE BASH
# Launcher.exe

CXX = g++
CXXFLAGS := #-Wall -Wextra -pedantic-errors -std=c++17 -g
EXEC = launcher
SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
OBJ = $(SOURCES:.cpp=.o)

all : $(EXEC) #doc

run : $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ -I Header/

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I Header/

clean :
	rm -rf $(OBJ)

mrproper: clean
	rm -f ./$(EXEC).exe