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
    cout << "1. Add a Recipe" << endl;
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

        switch (choice) {
            case 1: {
                // Add Recipe functionality
                string recipeName, directions, ingredientLine;
                int calories;
                vector<Ingredient> ingredients;

                cout << "Enter recipe name: ";
                cin.ignore();  // Clear the newline character left in the buffer
                getline(cin, recipeName);

                cout << "Enter ingredients (type 'done' when finished):\n";
                while (true) {
                    cout << "Enter ingredient (name quantity): ";
                    getline(cin, ingredientLine);
                    if (ingredientLine == "done") {
                        break;
                    }
                    // Parse the ingredient line here and add to ingredients vector
                    // This is a simplified example. You'll need to parse the line properly.
                    ingredients.push_back(Ingredient(ingredientLine, 1)); // Modify as per your Ingredient class constructor
                }

                // Get directions
                cout << "Enter directions (type 'END' on a new line to finish):" << endl;
                directions.clear();
                string line;
                while (getline(cin, line)) {
                    if (line == "END") {
                        break;
                    }
                    directions += line + "\n";
                }

                // Get calories
                cout << "Enter calories: ";
                cin >> calories;
                cin.ignore();  // Clear the newline character left in the buffer after reading calories

                // Create a new recipe and add it to the cookbook
                Recipe newRecipe(recipeName, ingredients, directions, calories);
                myCookbook.addRecipe(newRecipe);

                cout << "Recipe added successfully!\n";
                break;
            }
            case 2:
                // View Recipe functionality
                // Implement the logic to view a recipe
                break;
            case 3:
                // Search Recipes functionality
                // Implement the logic to search for recipes
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}