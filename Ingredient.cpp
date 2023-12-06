#include "Ingredient.h"
#include <sstream>
#include <iostream>

Ingredient::Ingredient(const std::string& fullDescription) {
    this->name = name;
        this->quantity = quantity;
}

// Removed parseDescription method as it's no longer needed with the new JSON structure
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

json Ingredient::toJson() const {
    return {{"name", name}, {"quantity", quantity}};
}

Ingredient Ingredient::fromJson(const json& j) {
    std::string name = j.at("name").get<std::string>();
    double quantity = j.at("quantity").get<double>();

    // Construct the full description string
    std::ostringstream fullDescription;
    fullDescription << quantity << " " << name;

    return Ingredient(fullDescription.str());
}
