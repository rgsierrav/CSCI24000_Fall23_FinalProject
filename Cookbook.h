#ifndef COOKBOOK_H
#define COOKBOOK_H

#include <vector>
#include <string>
#include "Recipe.h"

class Cookbook {
private:
    std::vector<Recipe> recipes;

public:
    Cookbook(); // Constructor to initialize the Cookbook
    void addRecipe(const Recipe& recipe); // Add a new recipe to the cookbook
    Recipe getRecipe(const std::string& recipeName) const; // Retrieve a recipe by name
    bool removeRecipe(const std::string& recipeName); // Remove a recipe by name
    std::vector<Recipe> searchRecipes(const std::string& searchQuery) const; // Search recipes by name
    int getTotalCalories() const; // Calculate and return the total calories of all recipes
    std::vector<std::string> getAllRecipeNames() const; // Get a list of names of all recipes
    std::vector<Recipe> searchRecipesByIngredient(const std::string& ingredientName) const; // Search recipes by ingredient
    int calculateTotalCalories(const std::vector<std::string>& recipeNames) const; // Calculate total calories for a list of recipes

};

#endif // COOKBOOK_H