#include "Cookbook.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

Cookbook::Cookbook() {
    // Constructor implementation (if needed)
}

std::string Cookbook::getTotalCalories() const {
    std::string calorieInfo;
    for (const auto& recipe : recipes) {
        calorieInfo += recipe.getName() + ": " + recipe.getCalories() + "\n";
    }
    return calorieInfo;
}


void Cookbook::addRecipe(const Recipe& recipe) {
    // Check for duplicate recipe names before adding
    auto it = std::find_if(recipes.begin(), recipes.end(),
                           [&](const Recipe& r) { return r.getName() == recipe.getName(); });
    if (it == recipes.end()) {
        recipes.push_back(recipe);
    } else {
        std::cout << "Recipe with the same name already exists." << std::endl;
    }
}

Recipe Cookbook::getRecipe(const std::string& recipeName) const {
    auto it = std::find_if(recipes.begin(), recipes.end(),
                           [&](const Recipe& recipe) { return recipe.getName() == recipeName; });
    if (it != recipes.end()) {
        return *it;
    } else {
        throw std::runtime_error("Recipe not found.");
    }
}

bool Cookbook::removeRecipe(const std::string& recipeName) {
    auto it = std::remove_if(recipes.begin(), recipes.end(), 
                             [&](const Recipe& recipe) { return recipe.getName() == recipeName; });
    if (it != recipes.end()) {
        recipes.erase(it, recipes.end());
        return true; // Indicates successful removal
    }
    return false; // Recipe not found
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

std::vector<std::string> Cookbook::getAllRecipeNames() const {
    std::vector<std::string> names;
    for (const auto& recipe : recipes) {
        names.push_back(recipe.getName());
    }
    return names;
}
