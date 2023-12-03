#include "Recipe.h"
#include <algorithm>

Recipe::Recipe(const std::string& name, const std::vector<Ingredient>& ingredients, const std::string& steps)
    : name(name), ingredients(ingredients), steps(steps) {
    // Constructor implementation
}

std::string Recipe::getName() const {
    return name;
}

void Recipe::addIngredient(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
}

void Recipe::removeIngredient(const std::string& ingredientName) {
    ingredients.erase(
        std::remove_if(ingredients.begin(), ingredients.end(), 
                       [&](const Ingredient& ingredient) { return ingredient.getName() == ingredientName; }),
        ingredients.end());
}

std::string Recipe::getSteps() const {
    return steps;
}

// Implement additional methods as needed
