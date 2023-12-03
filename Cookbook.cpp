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

std::vector<Recipe> Cookbook::searchRecipes(const std::string& searchQuery) const {
    std::vector<Recipe> foundRecipes;
    for (const auto& recipe : recipes) {
        if (recipe.getName().find(searchQuery) != std::string::npos) {
            foundRecipes.push_back(recipe);
        }
    }
    return foundRecipes;
}


// Implement additional functions as needed
