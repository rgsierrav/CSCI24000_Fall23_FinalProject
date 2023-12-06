#include "Cookbook.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>

Cookbook::Cookbook() {
    // Constructor implementation (if needed)
}

int extractNumericCalories(const std::string& calorieString) {
    std::istringstream iss(calorieString);
    int calories;
    if (iss >> calories) {
        return calories;
    } else {
        return 0; // Return 0 if the string does not start with a number
    }
}

int Cookbook::getTotalCalories() const {
    int totalCalories = 0;
    for (const auto& recipe : recipes) {
        totalCalories += extractNumericCalories(recipe.getCalories());
    }
    return totalCalories;
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

std::vector<Recipe> Cookbook::searchRecipesByIngredient(const std::string& ingredientName) const {
    std::vector<Recipe> foundRecipes;
    for (const auto& recipe : recipes) {
        for (const auto& ingredient : recipe.getIngredients()) {
            if (ingredient.getName().find(ingredientName) != std::string::npos) {
                foundRecipes.push_back(recipe);
                break; // Found the ingredient in this recipe, no need to check further
            }
        }
    }
    return foundRecipes;
}

int Cookbook::calculateTotalCalories(const std::vector<std::string>& recipeNames) const {
    int totalCalories = 0;
    for (const auto& name : recipeNames) {
        try {
            Recipe recipe = getRecipe(name);
            totalCalories += std::stoi(recipe.getCalories());
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << " - Skipping recipe: " << name << std::endl;
        }
    }
    return totalCalories;
}