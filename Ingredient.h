#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

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
    json toJson() const;
    static Ingredient fromJson(const json& j);
    // Additional methods as needed
};

#endif // INGREDIENT_H
