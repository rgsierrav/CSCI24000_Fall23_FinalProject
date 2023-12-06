CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
SRC = Cookbook.cpp Ingredient.cpp main.cpp Recipe.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = DigitalCookbook

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(EXEC)

clean:
	rm -f *.o $(EXEC)