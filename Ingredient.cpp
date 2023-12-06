#include "Ingredient.h"
#include <sstream>
#include <iostream>

Ingredient::Ingredient(const std::string& name, const std::string& quantity)
    : name(name), quantity(quantity) {}


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