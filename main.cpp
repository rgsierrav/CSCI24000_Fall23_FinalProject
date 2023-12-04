#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>
#include "nlohmann/json.hpp"
#include "Cookbook.h"
#include "Recipe.h"
#include "Ingredient.h"

using namespace std;
using json = nlohmann::json;

// Function to read JSON file
std::string readJsonFile(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Function to convert a string into a vector of Ingredient objects
std::vector<Ingredient> convertToIngredients(const std::string& ingredientsString) {
    std::vector<Ingredient> ingredientList;
    std::istringstream iss(ingredientsString);
    std::string line;

    while (std::getline(iss, line)) {
        // Assuming each line is formatted as 'quantity unit ingredient_name'
        std::istringstream lineStream(line);
        double quantity;
        std::string unit, ingredientName;

        lineStream >> quantity >> unit;
        std::getline(lineStream, ingredientName);
        ingredientName = unit + " " + ingredientName;

        Ingredient ingredientObj(ingredientName, quantity);
        ingredientList.push_back(ingredientObj);
    }

    return ingredientList;
}

// Function to extract the first numerical value from a string
int extractCalories(const std::string& calorieString) {
    std::istringstream iss(calorieString);
    int calories;
    iss >> calories;
    return calories;
}

// Function to parse JSON and add recipes to the cookbook
void parseJson(Cookbook& cookbook, const std::string& jsonString) {
    auto j = json::parse(jsonString);

    for (const auto& item : j) {
        std::string recipeName = item["Recipe Name"];
        std::vector<Ingredient> ingredients = convertToIngredients(item["Ingredients"]);
        std::string directions = item["Directions"];
        int calories = extractCalories(item["Calories"]);

        // Add the recipe to the cookbook
        Recipe recipe(recipeName, ingredients, directions, calories);
        cookbook.addRecipe(recipe);
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nDigital Cookbook" << endl;
    cout << "1. Add Recipe" << endl;
    cout << "2. View Recipe" << endl;
    cout << "3. Search Recipes" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to clear the input buffer
void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Cookbook myCookbook;
    string jsonFile = "recipes.json"; // Path to your JSON file
    string jsonString = readJsonFile(jsonFile);
    parseJson(myCookbook, jsonString);

    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            clearCin();
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        // Implement the rest of your menu functionality here
        // ...
    }

    return 0;
}
