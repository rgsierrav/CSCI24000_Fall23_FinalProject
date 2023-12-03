#include <iostream>
#include <string>
#include "Cookbook.h"
#include "Recipe.h"
#include "Ingredient.h"

using namespace std;

void displayMenu() {
    cout << "Digital Cookbook" << endl;
    cout << "1. Add Recipe" << endl;
    cout << "2. View Recipe" << endl;
    cout << "3. Search Recipes" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Cookbook myCookbook;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Inside the case 1 block in main.cpp
                cout << "Enter recipe name: ";
                string recipeName;
                cin.ignore(); // To clear the newline character in the input buffer
                getline(cin, recipeName);

                vector<Ingredient> ingredients;
                // Logic to add ingredients to the recipe
                // ...

                string steps;
                cout << "Enter the preparation steps: ";
                getline(cin, steps);

                Recipe newRecipe(recipeName, ingredients, steps);
                myCookbook.addRecipe(newRecipe);
                cout << "Recipe added successfully." << endl;
                break;
            }
            case 2: {
                // Inside the case 2 block in main.cpp
                cout << "Enter recipe name to view: ";
                string recipeName;
                cin.ignore();
                getline(cin, recipeName);

                try {
                    Recipe recipe = myCookbook.getRecipe(recipeName);
                    // Display recipe details
                    // ...
                } catch (const std::exception& e) {
                    cout << "Recipe not found." << endl;
                }
                break;
            }
            case 3: {
                // Search Recipes
                // Implement logic to search for recipes
                // Inside the case 3 block in main.cpp
                cout << "Enter search query: ";
                string searchQuery;
                cin.ignore(); // Clearing the input buffer
                getline(cin, searchQuery);

                vector<Recipe> foundRecipes = myCookbook.searchRecipes(searchQuery);

                if (foundRecipes.empty()) {
                    cout << "No recipes found matching your query." << endl;
                } else {
                    cout << "Found Recipes:" << endl;
                    for (const auto& recipe : foundRecipes) {
                        cout << recipe.getName() << endl; // Displaying the recipe names
                        // You can also display more details of each recipe here
                    }
                }
                break;
            }
            case 4: {
                cout << "Exiting Digital Cookbook." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}
