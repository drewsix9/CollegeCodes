#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
  string name;
  int age;
  int yearlevel;

public:
  void set_name() {
    cout << "\nEnter name of student: ";
    getline(cin, name);
  }
  string get_name() {
    return name;
  }

  void set_age() {
    cout << "\nEnter age of student: ";
    cin >> age;
  }
  int get_age() {
    return age;
  }

  void set_yearlevel() {
    cout << "\nEnter year level: ";
    cin >> yearlevel;
  }
  int get_yearlevel() {
    return yearlevel;
  }

  Student() {
    name = "Name";
    age = -1;
    yearlevel = -1;
  }
};

int main() {
  int size;
  printf("Enter how many students: ");
  cin >> size;
  cin.ignore(1000, '\n');

  Student students[size];

  for (int i = 0; i < size; i++) {
    students[i].set_name();
    students[i].set_age();
    students[i].set_yearlevel();
    cin.ignore(1000, '\n');
  }

  printf("Output: \n");
  cout << setw(5) << left << "     " << setw(20) << left << "Name:" << setw(1) << left << " " << setw(4) << left << "Age:" << setw(1) << left << " " << setw(11) << left << "Year Level:" << endl;
  cout << setw(5) << left << "     " << setw(20) << left << "====================" << setw(1) << left << " " << setw(4) << left << "====" << setw(1) << left << " " << setw(11) << left << "===========" << endl;
  for (int i = 0; i < size; i++) {
    cout << setw(5) << left << "     " << setw(20) << left << students[i].get_name() << setw(1) << left << " " << setw(4) << left << students[i].get_age() << setw(1) << left << " " << setw(11) << left << students[i].get_yearlevel() << endl;
  }

  return 0;
}

/*

3
dan mathew gamale
21
1
emyl jhumar abad
22
2
juan dela crux
24
3

*/