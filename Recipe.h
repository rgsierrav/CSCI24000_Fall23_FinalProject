#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>
#include "Ingredient.h"

class Recipe {
private:
    std::string name;
    std::string category;  // Added to store the recipe category
    std::vector<Ingredient> ingredients;
    std::string directions;
    std::string calories;

public:
    // Constructor for initializing Recipe objects
    Recipe(const std::string& name, const std::string& category, const std::string& calories, 
           const std::vector<Ingredient>& ingredients, const std::string& directions);    

    // Accessor methods
    std::string getCalories() const; // Get the recipe's calorie information
    std::string getName() const; // Get the name of the recipe
    void addIngredient(const Ingredient& ingredient); // Add an ingredient to the recipe
    std::string getSteps() const; // Get the recipe's preparation steps
    bool removeIngredient(const std::string& ingredientName); // Remove an ingredient by name
    void displayRecipe() const; // Display the details of the recipe
    std::string getDirections() const; // Get the recipe's preparation directions
    const std::vector<Ingredient>& getIngredients() const; // Get the list of ingredients
};

#endif // RECIPE_H
