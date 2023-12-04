#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
private:
    std::string ingredientLine; // Stores the entire ingredient line

public:
    explicit Ingredient(const std::string& line);
    std::string getIngredientLine() const;

    // If you still need these methods, declare them here
    std::string getName() const;
    double getQuantity() const;
};

#endif // INGREDIENT_H
