#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
private:
    std::string name;
    double quantity; 
    void parseDescription(const std::string& fullDescription);

public:
    explicit Ingredient(const std::string& fullDescription);
    std::string getName() const;
    void setQuantity(double newQuantity);
    double getQuantity() const;
    // Additional methods as needed
};

#endif // INGREDIENT_H