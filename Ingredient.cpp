#include "Ingredient.h"
#include <sstream>
#include <iostream>

Ingredient::Ingredient(const std::string& fullDescription) {
    std::istringstream iss(fullDescription);
    iss >> quantity; // Extract the quantity (assuming it's the first word)
    std::getline(iss >> std::ws, name); // Extract the rest of the line as the name
}

Ingredient::Ingredient(const std::string& name, const std::string& quantity)
    : name(name), quantity(quantity) {
    // Constructor implementation for separate name and quantity
}

void Ingredient::setQuantity(const std::string& newQuantity) {
    quantity = newQuantity;
}

std::string Ingredient::getQuantity() const {
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
    std::string quantity = j.at("quantity").get<std::string>(); // Changed to string

    return Ingredient(name, quantity);
}