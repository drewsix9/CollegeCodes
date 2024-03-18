#include <iostream>
#include <string>

using namespace std;

class Person { // base class
public:
  int id;
  string name;
  Person() { // default constructor
    id = 0;
    name = "";
  }
  Person(int id, string name) { // parameterized constructor
    this->id = id;
    this->name = name;
  }
};

class Doctor : public Person { // derived class inheriting from Person class
public:
  string specialty;
  Doctor() : Person(id, name) { // default constructor with base class constructor
    specialty = "";
  }

  static Doctor createDoctor() { // static method to create a doctor object
    Doctor doctor;
    cout << "Enter doctor's name: ";
    getline(cin, doctor.name);
    cout << "Enter doctor's specialty: ";
    getline(cin, doctor.specialty);
    return doctor;
  }
};

class Patient : public Person { // derived class inheriting from Person class
public:
  int age;
  string disease;
  Patient() : Person(id, name) { // default constructor with base class constructor
    age = 0;
    disease = "";
  }
  static Patient createPatient() { // static method to create a patient object
    Patient patient;
    cout << "Enter patient's name: ";
    getline(cin, patient.name);
    cout << "Enter patient's age: ";
    cin >> patient.age;
    cout << "Enter patient's disease: ";
    getline(cin, patient.disease);
    return patient;
  }
};

class Clinic {
private:
  int doctorCount;
  int patientCount;
  Doctor doctors[3];
  Patient patients[10];

public:
  Clinic() { // default constructor
    doctorCount = 0;
    patientCount = 0;
    for (int i = 0; i < 3; i++) {
      cout << "\nEnter doctor " << i + 1 << " : " << endl;
      doctorCount++;
      doctors[i] = Doctor::createDoctor(); // calling static method to create doctor object
      doctors[i].id = doctorCount;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
      cout << "\nEnter patient " << i + 1 << " : " << endl;
      patientCount++;
      patients[i] = Patient::createPatient(); // calling static method to create patient object
      patients[i].id = patientCount;
    }
  }

  void displayDoctors() {
    cout << "\n== Doctors ==" << endl;
    for (int i = 0; i < doctorCount; i++) {
      cout << "Doctor " << i + 1 << ": " << endl;
      cout << "ID: " << doctors[i].id << endl;
      cout << "Name: " << doctors[i].name << endl;
      cout << "Specialty: " << doctors[i].specialty << endl
           << endl;
    }
  }

  void displayPatients() {
    cout << "\n== Patients ==" << endl;
    for (int i = 0; i < patientCount; i++) {
      cout << "Patient " << i + 1 << ": " << endl;
      cout << "ID: " << patients[i].id << endl;
      cout << "Name: " << patients[i].name << endl;
      cout << "Age: " << patients[i].age << endl;
      cout << "Disease: " << patients[i].disease << endl
           << endl;
    }
  }
};

int main() {
  Clinic clinic;
  clinic.displayDoctors();
  clinic.displayPatients();
  return 0;
}

/*
Q: What is the purpose of the static keyword in C++?
A: The static keyword is used to create a static method or variable in a class. A static method or variable is shared by all objects of the class and can be called without creating an instance of the class.

Q: why we use static keyword in createDoctor() and createPatient()?
A:  is useful when we want to create an object without creating an instance of the class. In this case, we want to call createDoctor() and createPatient() methods without creating an instance of the Doctor and Patient class.

Q: Explain parameterized constructor with base class constructor.
A: A parameterized constructor is a constructor that takes parameters to initialize the object. In the example above, the Person class has a parameterized constructor that takes id and name as parameters to initialize the object. The Doctor and Patient classes inherit from the Person class and use the base class constructor
*/
