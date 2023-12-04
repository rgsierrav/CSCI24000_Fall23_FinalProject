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
    // Additional functions as needed
};

#endif // COOKBOOK_H
