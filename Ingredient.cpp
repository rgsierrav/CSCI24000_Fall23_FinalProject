#include "Ingredient.h"
#include <sstream>
#include <iostream>

Ingredient::Ingredient(const std::string& fullDescription) {
    parseDescription(fullDescription);
}

void Ingredient::parseDescription(const std::string& fullDescription) {
    // Example parsing logic (you will need to adjust this based on your specific format)
    std::istringstream iss(fullDescription);
    iss >> quantity;
    iss.ignore(); // Ignore the space between quantity and name
    std::getline(iss, name);
    // Trim leading whitespace from name, if necessary
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
