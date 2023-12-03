#ifndef COOKBOOK_H
#define COOKBOOK_H

#include <vector>
#include "Recipe.h"

class Cookbook {
private:
    std::vector<Recipe> recipes;

public:
    Cookbook();
    void addRecipe(const Recipe& recipe);
    Recipe getRecipe(const std::string& recipeName) const;
    void removeRecipe(const std::string& recipeName);
    // Additional functions as needed
};

std::vector<Recipe> searchRecipes(const std::string& searchQuery) const;


#endif // COOKBOOK_H
