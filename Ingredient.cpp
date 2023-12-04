#include "Ingredient.h"
#include <iostream> // Add this line

Ingredient::Ingredient(const std::string& name, double quantity)
    : name(name), quantity(quantity) {
    // Constructor implementation
}

std::string Ingredient::getName() const {
    return name;
}

void Ingredient::setQuantity(double newQuantity) {
    if (newQuantity >= 0) {
        quantity = newQuantity;
    } else {
        // Handle negative quantity, possibly with an error message or by setting it to zero
        std::cerr << "Quantity cannot be negative. Setting quantity to 0." << std::endl;
        quantity = 0;
    }
}

double Ingredient::getQuantity() const {
    return quantity;
}

// Implement additional methods as needed
