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
        // Directly use the line to create an Ingredient object
        std::istringstream lineStream(line);
        std::string name, quantity;
        getline(lineStream, name, ' '); // Extract name up to the first space
        getline(lineStream, quantity);  // Extract the rest as quantity
        ingredientList.push_back(Ingredient(name, quantity));
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
        std::string category = item["Category"];
        std::string calories = item["Calories"]; // Now a string
        std::vector<Ingredient> ingredients;

        for (const auto& ing : item["Ingredients"]) {
            std::string name = ing["name"];
            std::string quantity = ing["quantity"];
            ingredients.push_back(Ingredient(name, quantity));
        }

        std::string directions = item["Directions"];

        // Create and add the recipe to the cookbook
        Recipe recipe(recipeName, category, calories, ingredients, directions);
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
                    cout << "Enter ingredient (quantity and name): ";
                    getline(cin, ingredientLine);
                    if (ingredientLine == "done") {
                        break;
                    }
                    // Add the ingredient to the ingredients vector
                    std::istringstream lineStream(ingredientLine);
                    std::string name, quantity;
                    getline(lineStream, name, ' '); // Extract name up to the first space
                    getline(lineStream, quantity);  // Extract the rest as quantity
                    ingredients.push_back(Ingredient(name, quantity));
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
                string category;
                Recipe newRecipe(recipeName, category, to_string(calories), ingredients, directions);
                myCookbook.addRecipe(newRecipe);

                cout << "Recipe added successfully!\n";
                break;
            }
            case 2: {
                // List all recipes
                vector<string> recipeNames = myCookbook.getAllRecipeNames();
                if (recipeNames.empty()) {
                    cout << "No recipes available." << endl;
                    break;
                }

                cout << "Available Recipes:" << endl;
                for (size_t i = 0; i < recipeNames.size(); ++i) {
                    cout << i + 1 << ": " << recipeNames[i] << endl;
                }

                // Ask the user to choose a recipe
                cout << "Enter the number of the recipe you want to view: ";
                size_t recipeNumber;
                cin >> recipeNumber;

                // Validate input
                if (cin.fail() || recipeNumber < 1 || recipeNumber > recipeNames.size()) {
                    clearCin();
                    cout << "Invalid input. Please enter a valid number." << endl;
                    break;
                }

                try {
                    // Retrieve and display the recipe
                    string selectedRecipeName = recipeNames[recipeNumber - 1];
                    Recipe recipe = myCookbook.getRecipe(selectedRecipeName);

                    cout << "Recipe Name: " << recipe.getName() << endl;
                    cout << "Ingredients:" << endl;
                    for (const auto& ingredient : recipe.getIngredients()) {
                        std::ostringstream ingredientStream;
                        ingredientStream << ingredient.getQuantity() << " " << ingredient.getName();
                        std::string ingredientDisplay = ingredientStream.str();
                        cout << "- " << ingredientDisplay << endl;
                    }
                    cout << "Directions: " << recipe.getDirections() << endl;
                    cout << "Calories: " << recipe.getCalories() << endl;
                } catch (const std::runtime_error& e) {
                    cout << "An error occurred: " << e.what() << endl;
                }

                break;
            }
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