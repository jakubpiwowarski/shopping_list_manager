#include <iostream>
#include <map>
#include <fstream>

using namespace std;

void displayitems(map<string, int> &items){
  for (auto it = items.begin(); it != items.end(); ++it){
    cout << it -> first << "(" << it -> second << ")" << endl; 
  }
}
void addItem(map<string, int> &items){
  string item;
  int quantity;

  cout << "Enter the product name: ";
  cin >> item;
  cout << "Enter quantity: ";
  cin >> quantity; 
  if (items.count(item) > 0){
    items.at(item) += quantity;
    cout << endl;
    cout << "Increased the amount of existing product";
  } else {
    items.emplace(item, quantity);

  cout  << "Product added!" << endl; 
  }
}
void saveListToFile(map<string, int> &items) {
  ofstream shoppingList;
  shoppingList.open("shoppingList.txt");
  for (auto it = items.begin(); it != items.end(); ++it){
    shoppingList << it -> first << "(" << it -> second << ")" << endl; 
  }
  shoppingList.close();
}
void removeItem(map<string, int>& items) {
    string item;

    cout << "Enter the product name to remove: ";
    cin >> item;

    if (items.count(item) > 0) {
        items.erase(item);
        cout << "Product removed!" << endl;
    }
    else {
        cout << "Product not found in the list!" << endl;
    }
}
int main() {
  map<string, int> items;

  int option = -1; 

  while (option != 0){
    cout << endl;
    cout << "0. End program" << endl;
    cout << "1. Show items" << endl;
    cout << "2. Add item" << endl;
    cout << "3. Rmove item" << endl;
    cout << "4. Save list to file" << endl;
    cout << "Choose option: " << endl;

    cin >> option; 
    if (option == 1) {
      displayitems(items); 
    } else if (option == 2){
      addItem(items); 
    } else if (option == 4){
      saveListToFile(items);
    } else if (option == 3){
      removeItem(items);
    }
  
  
  }
}