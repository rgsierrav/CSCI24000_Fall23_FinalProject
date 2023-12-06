#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Ingredient {
private:
    std::string name;
    std::string quantity;  // Changed to string to accommodate quantities like "2/3 cup"

public:
    // Constructor for combined quantity and name
    Ingredient(const std::string& fullDescription);
    // Constructor for separate quantity and name
    Ingredient(const std::string& name, const std::string& quantity);
    
    std::string getName() const;
    std::string getQuantity() const;  // Return type changed to string
    json toJson() const;
    static Ingredient fromJson(const json& j);
    void setQuantity(const std::string& newQuantity);
    // Additional methods as needed
};

#endif // INGREDIENT_H
