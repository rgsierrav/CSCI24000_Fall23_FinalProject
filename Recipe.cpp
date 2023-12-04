#include "Recipe.h"
#include <iostream>
#include <algorithm>

Recipe::Recipe(const std::string& name, const std::vector<Ingredient>& ingredients, const std::string& steps, int calories)
    : name(name), ingredients(ingredients), steps(steps), calories(calories) {}

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

std::string Recipe::getSteps() const {
    return steps;
}

void Recipe::displayRecipe() const {
    std::cout << "Recipe Name: " << name << std::endl;
    std::cout << "Ingredients:" << std::endl;
    for (const auto& ingredient : ingredients) {
        std::cout << "- " << ingredient.getName() << ", Quantity: " << ingredient.getQuantity() << std::endl;
    }
    std::cout << "Preparation Steps: " << steps << std::endl;
}

// Implement additional methods as needed
