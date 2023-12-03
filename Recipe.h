#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>
#include "Ingredient.h"

class Recipe {
private:
    std::string name;
    std::vector<Ingredient> ingredients;
    std::string steps;

public:
    Recipe(const std::string& name, const std::vector<Ingredient>& ingredients, const std::string& steps);
    std::string getName() const;
    void addIngredient(const Ingredient& ingredient);
    void removeIngredient(const std::string& ingredientName);
    std::string getSteps() const;
    // Additional methods as needed
};

#endif // RECIPE_H
