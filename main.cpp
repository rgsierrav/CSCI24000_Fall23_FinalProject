#include <iostream>
#include <string>
#include <limits>
#include "Cookbook.h"
#include "Recipe.h"
#include "Ingredient.h"

using namespace std;

void displayMenu() {
    cout << "\nDigital Cookbook" << endl;
    cout << "1. Add Recipe" << endl;
    cout << "2. View Recipe" << endl;
    cout << "3. Search Recipes" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Cookbook myCookbook;
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
                cout << "Enter recipe name: ";
                string recipeName;
                clearCin();
                getline(cin, recipeName);

                vector<Ingredient> ingredients;
                cout << "How many ingredients? ";
                int numIngredients;
                cin >> numIngredients;

                if (cin.fail()) {
                    clearCin();
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }

                clearCin();
                for (int i = 0; i < numIngredients; ++i) {
                    cout << "Enter ingredient name: ";
                    string ingredientName;
                    getline(cin, ingredientName);

                    cout << "Enter quantity: ";
                    double quantity;
                    cin >> quantity;

                    if (cin.fail()) {
                        clearCin();
                        cout << "Invalid input. Please enter a number." << endl;
                        break;
                    }

                    clearCin();
                    ingredients.push_back(Ingredient(ingredientName, quantity));
                }

                string steps;
                cout << "Enter the preparation steps: ";
                getline(cin, steps);

                Recipe newRecipe(recipeName, ingredients, steps);
                myCookbook.addRecipe(newRecipe);
                cout << "Recipe added successfully." << endl;
                break;
            }
            case 2: {
                cout << "Enter recipe name to view: ";
                string recipeName;
                clearCin();
                getline(cin, recipeName);

                try {
                    Recipe recipe = myCookbook.getRecipe(recipeName);
                    recipe.displayRecipe();
                } catch (const std::exception& e) {
                    cout << "Recipe not found." << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter search query: ";
                string searchQuery;
                clearCin();
                getline(cin, searchQuery);

                vector<Recipe> foundRecipes = myCookbook.searchRecipes(searchQuery);

                if (foundRecipes.empty()) {
                    cout << "No recipes found matching your query." << endl;
                } else {
                    cout << "Found Recipes:" << endl;
                    for (const auto& recipe : foundRecipes) {
                        cout << recipe.getName() << endl;
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
