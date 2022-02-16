# HAYAT Rahim - MAKEFILE BASH
# Launcher.exe

CXX = g++
EXEC = launcher
SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
OBJ = $(SOURCES:.cpp=.o)

all : $(EXEC) #doc

run : $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ -I Header/

%.o : %.cpp
	$(CXX) -o $@ -c $< -I Header/

clean :
	rm -rf $(OBJ)

mrproper: clean
	rm -f ./$(EXEC).exe