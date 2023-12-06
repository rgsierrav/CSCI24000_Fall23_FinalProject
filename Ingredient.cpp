#include "Ingredient.h"
#include <sstream>
#include <iostream>

Ingredient::Ingredient(const std::string& fullDescription) {
    // Constructor for Ingredient with combined quantity and name
    std::istringstream iss(fullDescription);
    iss >> quantity; // Extract the quantity (assuming it's the first word)
    std::getline(iss >> std::ws, name); // Extract the rest of the line as the name
}

Ingredient::Ingredient(const std::string& name, const std::string& quantity)
    : name(name), quantity(quantity) {
    // Constructor implementation for Ingredient with separate name and quantity
}

void Ingredient::setQuantity(const std::string& newQuantity) {
    // Setter function to update the quantity
    quantity = newQuantity;
}

std::string Ingredient::getQuantity() const {
    // Getter function to retrieve the quantity
    return quantity;
}

std::string Ingredient::getName() const {
    // Getter function to retrieve the name
    return name;
}

json Ingredient::toJson() const {
    // Convert Ingredient object to JSON
    return {{"name", name}, {"quantity", quantity}};
}

Ingredient Ingredient::fromJson(const json& j) {
    // Create an Ingredient object from JSON data
    std::string name = j.at("name").get<std::string>();
    std::string quantity = j.at("quantity").get<std::string>(); // Quantity is now stored as a string

    return Ingredient(name, quantity);
}