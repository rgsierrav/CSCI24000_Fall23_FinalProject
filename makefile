CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

SRC = Cookbook.cpp Ingredient.cpp main.cpp Recipe.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = DigitalCookbook

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
    # ^ This line and any commands below should be indented with a tab.

clean:
	rm -f src/*.o $(EXEC)
    # ^ This line and any commands below should be indented with a tab.
