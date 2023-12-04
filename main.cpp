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
        std::istringstream lineStream(line);
        std::string quantity, restOfLine, ingredientName;

        // Read the quantity (which may include a range like '1-2')
        lineStream >> quantity;
        std::getline(lineStream, restOfLine); // Get the rest of the line

        // Check if the quantity is a range
        size_t dashPos = quantity.find('-');
        if (dashPos != std::string::npos) {
            // It's a range, keep it as is
            ingredientName = quantity + restOfLine;
        } else {
            // It's a standard quantity, separate quantity and name
            std::istringstream restStream(restOfLine);
            std::string unit;
            restStream >> unit;
            std::getline(restStream, ingredientName); // Get the rest of the line as the ingredient name
            ingredientName = unit + ingredientName; // Concatenate unit and name
            ingredientName = quantity + " " + ingredientName; // Prepend quantity
        }

        ingredientList.push_back(Ingredient(ingredientName));
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
                    cout << "Enter ingredient (quantity and name): ";
                    getline(cin, ingredientLine);
                    if (ingredientLine == "done") {
                        break;
                    }
                    // Add the ingredient to the ingredients vector
                    ingredients.push_back(Ingredient(ingredientLine));
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