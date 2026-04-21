#include <iostream>
#include <queue>
#include <string>
using namespace std;
// Structure for Patient
struct Patient {
    int id;
    string name;
    int age;
};
// Global list (array) and queue
Patient patients[100];
int count = 0;
queue<int> waitingQueue; // stores patient IDs
// Function to Add Patient
void addPatient() {
    if (count >= 100) {
        cout << "Patient list is full!\n";
        return;
    }
cout << "\nEnter Patient ID: ";
    cin >> patients[count].id;
    cout << "Enter Name: ";
    cin >> patients[count].name;
    cout << "Enter Age: ";
    cin >> patients[count].age;
 waitingQueue.push(patients[count].id);
    count++;
	cout << "Patient added successfully!\n";
}
// Function to View Patients
void viewPatients() {
    if (count == 0) {
        cout << "No patients available!\n";
        return;
    }
 cout << "\n--- Patient List ---\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << patients[i].id
             << ", Name: " << patients[i].name
             << ", Age: " << patients[i].age << endl;
    }
}
// Function to Search Patient
void searchPatient() {
    int id;
    cout << "\nEnter Patient ID to search: ";
    cin >> id;
  for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            cout << "Patient Found!\n";
            cout << "Name: " << patients[i].name
                 << ", Age: " << patients[i].age << endl;
            return;
        }
    }
  cout << "Patient not found!\n";
}
// Function to Delete Patient
void deletePatient() {
    int id;
    cout << "\nEnter Patient ID to delete: ";
    cin >> id;
 for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            count--;
            cout << "Patient deleted successfully!\n";
            return;
        }
    }
 cout << "Patient not found!\n";
}
// Main Function
int main() {
    int choice;
 do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
} 
while (choice != 5);

    return 0;
}
