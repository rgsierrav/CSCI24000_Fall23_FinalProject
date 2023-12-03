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
                // Add Recipe
                // You will need to implement logic to create a new recipe
                // and add it to the cookbook
                break;
            }
            case 2: {
                // View Recipe
                // Implement logic to view a specific recipe
                break;
            }
            case 3: {
                // Search Recipes
                // Implement logic to search for recipes
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
