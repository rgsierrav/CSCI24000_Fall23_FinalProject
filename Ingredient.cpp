#include "Ingredient.h"
#include <sstream>

// Constructor implementation
Ingredient::Ingredient(const std::string& line) : ingredientLine(line) {}

// Getter implementation for the entire line
std::string Ingredient::getIngredientLine() const {
    return ingredientLine;
}

// Implement getName to extract the name part from ingredientLine
std::string Ingredient::getName() const {
    std::istringstream iss(ingredientLine);
    std::string name;
    iss >> name; // This extracts only the first word. You'll need to adjust this based on your format.
    return name;
}

// Implement getQuantity to extract the quantity part from ingredientLine
double Ingredient::getQuantity() const {
    std::istringstream iss(ingredientLine);
    double quantity;
    iss >> quantity; // This assumes the quantity is the first part of the string.
    return quantity;
}
