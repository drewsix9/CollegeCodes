#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Products {
  string _name;
  int _id;
  float _price;
  Products();
  void printRecord();
};

int main() {
  Products prod;
  prod.printRecord();
}

Products::Products() {
  cout << "Enter product details:\n";
  cout << "Product Name: ";
  getline(cin, _name);
  cout << "Product ID: ";
  cin >> _id;
  cout << "Price: ";
  cin >> _price;
}

void Products::printRecord() {
  cout << "\nProduct details:\n";
  cout << "Name: " << this->_name << endl;
  cout << "ID: " << this->_id << endl;
  cout << "Price: " << fixed << setprecision(2) << this->_price;
}