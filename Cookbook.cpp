#include "Cookbook.h"
#include <algorithm>

Cookbook::Cookbook() {
    // Constructor implementation (if needed)
}

void Cookbook::addRecipe(const Recipe& recipe) {
    recipes.push_back(recipe);
}

Recipe Cookbook::getRecipe(const std::string& recipeName) const {
    for (const auto& recipe : recipes) {
        if (recipe.getName() == recipeName) {
            return recipe;
        }
    }
    // Handle the case where the recipe is not found
    // This could be throwing an exception or returning a default Recipe object
}

void Cookbook::removeRecipe(const std::string& recipeName) {
    recipes.erase(
        std::remove_if(recipes.begin(), recipes.end(), 
                       [&](const Recipe& recipe) { return recipe.getName() == recipeName; }),
        recipes.end());
}

// Implement additional functions as needed
