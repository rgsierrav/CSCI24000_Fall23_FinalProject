#ifndef COOKBOOK_H
#define COOKBOOK_H

#include <vector>
#include <string>
#include "Recipe.h"

class Cookbook {
private:
    std::vector<Recipe> recipes;

public:
    Cookbook();
    void addRecipe(const Recipe& recipe);
    Recipe getRecipe(const std::string& recipeName) const;
    bool removeRecipe(const std::string& recipeName);
    std::vector<Recipe> searchRecipes(const std::string& searchQuery) const;
    int getTotalCalories() const;
    std::vector<std::string> getAllRecipeNames() const; // Add this line
    std::vector<Recipe> searchRecipesByIngredient(const std::string& ingredientName) const;
    int calculateTotalCalories(const std::vector<std::string>& recipeNames) const;
};

#endif // COOKBOOK_H
