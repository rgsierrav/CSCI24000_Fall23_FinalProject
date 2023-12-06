#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Ingredient {
private:
    std::string name;
    std::string quantity;  // Quantity changed to string to accommodate various formats like "2/3 cup"

public:
    // Constructor for combined quantity and name
    Ingredient(const std::string& fullDescription);

    // Constructor for separate quantity and name
    Ingredient(const std::string& name, const std::string& quantity);

    // Getter for ingredient name
    std::string getName() const;

    // Getter for ingredient quantity (now returns a string)
    std::string getQuantity() const;

    // Convert Ingredient object to JSON
    json toJson() const;

    // Create an Ingredient object from JSON
    static Ingredient fromJson(const json& j);

    // Setter for quantity
    void setQuantity(const std::string& newQuantity);
};

#endif // INGREDIENT_H