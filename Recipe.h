#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>
#include "Ingredient.h"

class Recipe {
private:
    std::string name;
    std::string category;  // Add this line
    std::vector<Ingredient> ingredients;
    std::string directions;
    std::string calories;

public:
    Recipe(const std::string& name, const std::string& category, const std::string& calories, 
           const std::vector<Ingredient>& ingredients, const std::string& directions);    
    std::string getCalories() const;
    std::string getName() const;
    void addIngredient(const Ingredient& ingredient);
    std::string getSteps() const;
    bool removeIngredient(const std::string& ingredientName);
    void displayRecipe() const;
    std::string getDirections() const;
    const std::vector<Ingredient>& getIngredients() const; // Add this line

};

#endif // RECIPE_H
