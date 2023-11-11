#include <iostream>
#include <string>
#include <vector>
// #include <con.io>
#include <iomanip>

using namespace std;

struct Contact
{
	string name;
	string num;
	string email;
};

vector<Contact> phonebook;
int count = 0;
int *ptr = &count;

void addContact()
{
	Contact newContact;
	(*ptr)++;
	cout << "\nAdd New Record" << endl;
	cout << "Name: ";
	getline(cin, newContact.name);
	cout << "Phone Number: ";
	getline(cin, newContact.num);
	cout << "Email: ";
	getline(cin, newContact.email);
	phonebook.push_back(newContact);
	cout << "\nContact Successfully Recorded!" << endl;
	cout << "\nPress any Enter to continue...";
	getchar();
}

void displayContact()
{
	cout << endl;
	cout << setfill('_') << setw(80) << "" << endl
		 << endl;
	cout << setfill(' ') << setw(30) << ""
		 << "List of All Records" << endl;
	cout << setfill('.') << setw(80) << "" << endl;
	cout << setfill(' ') << setw(5) << left << "No." << setfill(' ') << setw(20) << left << "Name" << setfill(' ') << setw(20) << left << "Phone Number" << setfill(' ') << setw(30) << left << "Email" << endl;
	cout << setfill('-') << setw(80) << "" << endl;

	int i = 0;
	for (auto itr = phonebook.begin(); itr != phonebook.end(); itr++)
	{
		cout << setfill(' ') << setw(5) << left << i << setfill(' ') << setw(20) << left << itr->name << setfill(' ') << setw(20) << left << itr->num << setfill(' ') << setw(30) << left << itr->email << endl;
		i++;
	}
	cout << setfill('_') << setw(80) << "" << endl;
	cout << "\nPress any Enter to continue...";
	getchar();
}

void searchContact()
{
	int isFound = 0;
	cout << endl;
	string input;
	cout << "Enter name to search: ";
	getline(cin, input);
	for (auto itr = phonebook.begin(); itr != phonebook.end(); itr++)
	{
		if (itr->name == input)
		{
			cout << endl;
			cout << setfill('_') << setw(70) << "" << endl
				 << endl;
			cout << setfill(' ') << setw(25) << ""
				 << "Contact Found!" << endl;
			cout << setfill('.') << setw(70) << "" << endl;
			cout << setfill(' ') << setw(20) << left << "Name" << setfill(' ') << setw(20) << left << "Phone Number" << setfill(' ') << setw(30) << left << "Email" << endl;
			cout << setfill('-') << setw(70) << "" << endl;
			cout << setfill(' ') << setw(20) << left << itr->name << setfill(' ') << setw(20) << left << itr->num << setfill(' ') << setw(30) << left << itr->email << endl;
			cout << setfill('_') << setw(70) << "" << endl;
			isFound = 1;
			break;
		}
	}

	if (isFound == 0)
	{
		// cout << "\nContact Not Found!" << endl;
		cout << endl;
		cout << setfill('_') << setw(80) << "" << endl
			 << endl;
		cout << setfill(' ') << setw(31) << ""
			 << "Contact NOT Found!" << endl;
		cout << setfill('.') << setw(80) << "" << endl;
		cout << setfill(' ') << setw(20) << left << "Name" << setfill(' ') << setw(20) << left << "Phone Number" << setfill(' ') << setw(30) << left << "Email" << endl;
		cout << setfill('-') << setw(80) << "" << endl;
		cout << setfill('_') << setw(80) << "" << endl;
	}

	cout << "\nPress any Enter to continue...";
	getchar();
}

void deleteContact()
{
	cout << endl;
	cout << setfill('_') << setw(80) << "" << endl
		 << endl;
	cout << setfill(' ') << setw(32) << ""
		 << "Delete a Record" << endl;
	cout << setfill('.') << setw(80) << "" << endl;
	cout << setfill(' ') << setw(5) << left << "No." << setfill(' ') << setw(20) << left << "Name" << setfill(' ') << setw(20) << left << "Phone Number" << setfill(' ') << setw(30) << left << "Email" << endl;
	cout << setfill('-') << setw(80) << "" << endl;

	int i = 0;
	for (auto itr = phonebook.begin(); itr != phonebook.end(); itr++)
	{
		cout << setfill(' ') << setw(5) << left << i << setfill(' ') << setw(20) << left << itr->name << setfill(' ') << setw(20) << left << itr->num << setfill(' ') << setw(30) << left << itr->email << endl;
		i++;
	}
	cout << setfill('_') << setw(80) << "" << endl;

	int choice;
	cout << "\nEnter No. to be deleted: ";
	cin >> choice;
	cin.ignore();
	if (choice > count || choice <= 0)
	{
		cout << "\nWrong input, please try again" << endl;
	}
	else
	{
		string tempname = (phonebook.begin() + choice)->name;
		string tempnum = (phonebook.begin() + choice)->num;
		string tempemail = (phonebook.begin() + choice)->email;
		phonebook.erase(phonebook.begin() + choice);
		(*ptr)--;
		cout << endl;
		cout << setfill('_') << setw(70) << "" << endl
			 << endl;
		cout << setfill(' ') << setw(20) << ""
			 << "Contact Successfully Deleted!" << endl;
		cout << setfill('.') << setw(70) << "" << endl;
		cout << setfill(' ') << setw(20) << left << "Name" << setfill(' ') << setw(20) << left << "Phone Number" << setfill(' ') << setw(30) << left << "Email" << endl;
		cout << setfill('-') << setw(70) << "" << endl;
		cout << setfill(' ') << setw(20) << left << tempname << setfill(' ') << setw(20) << left << tempnum << setfill(' ') << setw(30) << left << tempemail << endl;
		cout << setfill('_') << setw(70) << "" << endl;
	}

	cout << "\nPress any Enter to continue...";
	getchar();
}

int main()
{
	while (1)
	{
		int choice = 0;
		cout << endl;
		cout << setfill('_') << setw(42) << "" << endl;
		cout << "\nYet Another  Rudimentary Phonebook  (YARP)" << endl;
		cout << setfill('_') << setw(42) << "" << endl;

		cout << endl;
		cout << setfill(' ') << setw(16) << "" << setfill('*') << setw(3) << ""
			 << "Menu" << setw(3) << "" << endl;
		cout << setfill(' ') << setw(16) << ""
			 << "1 Add" << endl;
		cout << setfill(' ') << setw(16) << ""
			 << "2 Display" << endl;
		cout << setfill(' ') << setw(16) << ""
			 << "3 Search" << endl;
		cout << setfill(' ') << setw(16) << ""
			 << "4 Delete" << endl;
		cout << setfill(' ') << setw(16) << ""
			 << "5 Exit" << endl;
		cout << setfill(' ') << setw(16) << "" << setfill('*') << setw(10) << "" << endl
			 << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
			addContact();
			break;
		case 2:
			displayContact();
			break;
		case 3:
			searchContact();
			break;
		case 4:
			deleteContact();
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
		// system("cls");
	}

	return 0;
}