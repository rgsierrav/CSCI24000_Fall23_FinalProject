#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
private:
    std::string name;
    double quantity; // Consider adding a unit of measurement attribute if needed

public:
    Ingredient(const std::string& name, double quantity) : name(name), quantity(quantity) {}
    std::string getName() const;
    void setQuantity(double newQuantity);
    double getQuantity() const;
    // Additional methods as needed
};

#endif // INGREDIENT_H
