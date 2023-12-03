CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = DigitalCookbook

all: $(EXEC)

$(EXEC): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
    rm -f src/*.o $(EXEC)
