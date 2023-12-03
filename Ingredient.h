#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
private:
    std::string name;
    double quantity;
    // Add more attributes if needed, like unit of measurement

public:
    Ingredient(const std::string& name, double quantity);
    std::string getName() const;
    void setQuantity(double newQuantity);
    double getQuantity() const;
    // Additional methods as needed
};

#endif // INGREDIENT_H
