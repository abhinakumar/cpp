#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants for grid size and maximum moves
const int GRID_SIZE = 5;
const int MAX_MOVES = 10;

// Function to display the grid
void displayGrid(int playerX, int playerY, int targetX, int targetY) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == playerY && j == playerX) {
                cout << "P ";
            } else if (i == targetY && j == targetX) {
                cout << "T ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to calculate the Manhattan distance between two points
int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    // Generate random positions for the player and target
    int playerX = rand() % GRID_SIZE;
    int playerY = rand() % GRID_SIZE;
    int targetX = rand() % GRID_SIZE;
    int targetY = rand() % GRID_SIZE;

    // Display the initial grid
    displayGrid(playerX, playerY, targetX, targetY);

    // Game loop
    int moves = 0;
    while (moves < MAX_MOVES) {
        // Get the player's move
        char move;
        cout << "Enter your move (W/A/S/D): ";
        cin >> move;

        // Update the player's position based on the move
        switch (move) {
            case 'W':
            case 'w':
                if (playerY > 0) {
                    playerY--;
                }
                break;
            case 'A':
            case 'a':
                if (playerX > 0) {
                    playerX--;
                }
                break;
            case 'S':
            case 's':
                if (playerY < GRID_SIZE - 1) {
                    playerY++;
                }
                break;
            case 'D':
            case 'd':
                if (playerX < GRID_SIZE - 1) {
                    playerX++;
                }
                break;
            default:
                cout << "Invalid move! Please try again." << endl;
                continue;  // Skip the rest of the loop and restart
        }

        // Display the updated grid
        displayGrid(playerX, playerY, targetX, targetY);

        // Check if the player has caught the target
        if (playerX == targetX && playerY == targetY) {
            cout << "Congratulations! You caught the target!" << endl;
            break;
        }

        // Calculate the distance between the player and target
        int distance = calculateDistance(playerX, playerY, targetX, targetY);
        cout << "Distance to target: " << distance << endl;

        moves++;
    }

    // Check if the player ran out of moves
    if (moves == MAX_MOVES) {
        cout << "Game over! You ran out of moves." << endl;
    }

    return 0;
}


//This project is a simple inventory management system for a store

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    int quantity;
    double price;

    Product(string name, int quantity, double price) {
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(string name, int quantity, double price) {
        Product product(name, quantity, price);
        products.push_back(product);
    }

    void displayProducts() {
        cout << "Inventory:" << endl;
        cout << "------------------------------" << endl;
        cout << "Name\t\tQuantity\tPrice" << endl;
        cout << "------------------------------" << endl;
        for (const auto& product : products) {
            cout << product.name << "\t\t" << product.quantity << "\t\t" << product.price << endl;
        }
        cout << "------------------------------" << endl;
    }

    void sellProduct(string name, int quantity) {
        for (auto& product : products) {
            if (product.name == name) {
                if (product.quantity >= quantity) {
                    product.quantity -= quantity;
                    cout << "Sold " << quantity << " " << name << "(s)." << endl;
                } else {
                    cout << "Insufficient quantity for " << name << "." << endl;
                }
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void updatePrice(string name, double price) {
        for (auto& product : products) {
            if (product.name == name) {
                product.price = price;
                cout << "Price updated for " << name << "." << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }
};

int main() {
    Inventory inventory;

    inventory.addProduct("Item 1", 10, 9.99);
    inventory.addProduct("Item 2", 5, 19.99);
    inventory.addProduct("Item 3", 3, 14.99);

    inventory.displayProducts();

    inventory.sellProduct("Item 1", 5);
    inventory.updatePrice("Item 2", 24.99);

    inventory.displayProducts();

    return 0;
}
// or we can write this way also

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    int quantity;
    double price;

    Product(string name, int quantity, double price) {
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(string name, int quantity, double price) {
        Product product(name, quantity, price);
        products.push_back(product);
    }

    void displayProducts() {
        cout << "Inventory:" << endl;
        cout << "------------------------------" << endl;
        cout << "Name\t\tQuantity\tPrice" << endl;
        cout << "------------------------------" << endl;
        for (const auto& product : products) {
            cout << product.name << "\t\t" << product.quantity << "\t\t" << product.price << endl;
        }
        cout << "------------------------------" << endl;
    }

    void sellProduct(string name, int quantity) {
        for (auto& product : products) {
            if (product.name == name) {
                if (product.quantity >= quantity) {
                    product.quantity -= quantity;
                    cout << "Sold " << quantity << " " << name << "(s)." << endl;
                } else {
                    cout << "Insufficient quantity for " << name << "." << endl;
                }
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void updatePrice(string name, double price) {
        for (auto& product : products) {
            if (product.name == name) {
                product.price = price;
                cout << "Price updated for " << name << "." << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void removeProduct(string name) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->name == name) {
                products.erase(it);
                cout << "Removed " << name << " from inventory." << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void addQuantity(string name, int quantity) {
        for (auto& product : products) {
            if (product.name == name) {
                product.quantity += quantity;
                cout << "Added " << quantity << " " << name << "(s) to inventory." << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }
};

int main() {
    Inventory inventory;

    inventory.addProduct("Item 1", 10, 9.99);
    inventory.addProduct("Item 2", 5, 19.99);
    inventory.addProduct("Item 3", 3, 14.99);

    inventory.displayProducts();

    inventory.sellProduct("Item 1", 5);
    inventory.updatePrice("Item 2", 24.99);
    inventory.removeProduct("Item 3");

    inventory.displayProducts();

    inventory.addQuantity("Item 1", 2);
    inventory.addProduct("Item 4", 7, 12.99);

    inventory.displayProducts();

    return 0;
}
