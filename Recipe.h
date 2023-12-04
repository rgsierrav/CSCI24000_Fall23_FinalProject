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
    int calories;

public:
    Recipe(const std::string& name, const std::vector<Ingredient>& ingredients, const std::string& steps, int calories);
    int getCalories() const;    std::string getName() const;
    void addIngredient(const Ingredient& ingredient);
    std::string getSteps() const;
    bool removeIngredient(const std::string& ingredientName);
    void displayRecipe() const;

    // Additional methods as needed
};

#endif // RECIPE_H
