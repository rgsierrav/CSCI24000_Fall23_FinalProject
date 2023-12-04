#include "Recipe.h"
#include <iostream>
#include <algorithm>

Recipe::Recipe(const std::string& name, const std::vector<Ingredient>& ingredients, const std::string& directions, int calories)
    : name(name), ingredients(ingredients), directions(directions), calories(calories) {
    // constructor body (if needed)
}

int Recipe::getCalories() const {
    return calories;
}


std::string Recipe::getName() const {
    return name;
}

void Recipe::addIngredient(const Ingredient& ingredient) {
    auto it = std::find_if(ingredients.begin(), ingredients.end(),
                           [&](const Ingredient& ing) { return ing.getName() == ingredient.getName(); });
    if (it != ingredients.end()) {
        it->setQuantity(it->getQuantity() + ingredient.getQuantity());
    } else {
        ingredients.push_back(ingredient);
    }
}

bool Recipe::removeIngredient(const std::string& ingredientName) {
    auto it = std::remove_if(ingredients.begin(), ingredients.end(), 
                             [&](const Ingredient& ingredient) { return ingredient.getName() == ingredientName; });
    if (it != ingredients.end()) {
        ingredients.erase(it, ingredients.end());
        return true; // Indicates successful removal
    }
    return false; // Ingredient not found
}

std::string Recipe::getDirections() const {
    return directions;
}

void Recipe::displayRecipe() const {
    std::cout << "Recipe Name: " << name << std::endl;
    std::cout << "Ingredients:" << std::endl;
    for (const auto& ingredient : ingredients) {
        std::cout << "- " << ingredient.getName() << ", Quantity: " << ingredient.getQuantity() << std::endl;
    }
    std::cout << "Directions " << directions << std::endl;
}
