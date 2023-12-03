#include "Ingredient.h"

Ingredient::Ingredient(const std::string& name, double quantity)
    : name(name), quantity(quantity) {
    // Constructor implementation
}

std::string Ingredient::getName() const {
    return name;
}

void Ingredient::setQuantity(double newQuantity) {
    quantity = newQuantity;
}

double Ingredient::getQuantity() const {
    return quantity;
}

// Implement additional methods as needed
