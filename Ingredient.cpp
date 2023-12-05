#include "Ingredient.h"
#include <sstream>
#include <iostream>

Ingredient::Ingredient(const std::string& fullDescription) {
    parseDescription(fullDescription);
}

void Ingredient::parseDescription(const std::string& fullDescription) {
    size_t spacePos = fullDescription.find(' ');
    if (spacePos != std::string::npos) {
        std::string quantityStr = fullDescription.substr(0, spacePos);
        name = fullDescription.substr(spacePos + 1);

        // Check if quantityStr contains a dash, indicating a range
        if (quantityStr.find('-') != std::string::npos) {
            quantity = 0; // Set to 0 or handle differently if a range is not a single value
        } else {
            // Convert quantityStr to a number
            std::istringstream iss(quantityStr);
            iss >> quantity;
        }
    } else {
        // Handle the case where there's no space (e.g., just a name without quantity)
        name = fullDescription;
        quantity = 0;
    }
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

std::string Ingredient::getName() const {
    return name;
}
