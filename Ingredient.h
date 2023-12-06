Nstd::string quantity;  // Changed to string to accommodate quantities like "2/3 cupIngredient(const std::string& name, const std::string& quantity);
#define INGREDIENT_H

#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Ingredient {
private:
    std::string name;
     std::string quantity;  // Changed to string to accommodate quantities like "2/3 cup"
    void parseDescription(const std::string& fullDescription);

public:
    Ingredient(const std::string& name, const std::string& quantity);
    std::string getName() const;
    std::string getQuantity() const;  // Return type changed to string
    std::string getQuantity() const;  // Return type changed to string
    json toJson() const;
    static Ingredient fromJson(const json& j);
    // Additional methods as needed
};

#endif // INGREDIENT_H
