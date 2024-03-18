#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
  int id;
  string name;
  Person() {
    id = 0;
    name = "";
  }
  Person(int id, string name) { // parameterized constructor with base class constructor
    this->id = id;
    this->name = name;
  }
};

class Doctor : public Person {

public:
  string specialty;
  Doctor() : Person(id, name) {
    specialty = "";
  }

  static Doctor createDoctor() {
    Doctor doctor;
    cout << "Enter doctor's name: ";
    getline(cin, doctor.name);
    cout << "Enter doctor's specialty: ";
    getline(cin, doctor.specialty);
    return doctor;
  }
};

class Patient : public Person {
public:
  int age;
  string disease;
  Patient() : Person(id, name) { // default constructor with base class constructor
    age = 0;
    disease = "";
  }
  static Patient createPatient() {
    Patient patient;
    cout << "Enter patient's name: ";
    getline(cin, patient.name);
    cout << "Enter patient's age: ";
    patient.age = rand() % 100;
    // cin.ignore();
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
  // Clinic constructor
  Clinic() {
    doctorCount = 0;
    patientCount = 0;
    for (int i = 0; i < 3; i++) {
      cout << "\nEnter doctor " << i + 1 << " : " << endl;
      doctorCount++;
      doctors[i] = Doctor::createDoctor();
      doctors[i].id = doctorCount;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
      cout << "\nEnter patient " << i + 1 << " : " << endl;
      patientCount++;
      patients[i] = Patient::createPatient();
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
