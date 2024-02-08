#include <iostream>
using namespace std;

// Employee structure
struct Employee {
    int id;
    string name;
    string department;
};

int main() {
    Employee employees[100];
    int count = 0;
    int choice;

    do {
        cout << "Employee Management System" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Update Employee Details" << endl;
        cout << "5. Delete Employee" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count < 100) {
                    Employee emp; 
                    
                    cout << "Enter employee ID: ";
                    cin >> emp.id;
                    cin.ignore(); // Ignore the newline character
                    cout << "Enter employee name: ";
                    getline(cin, emp.name);
                    cout << "Enter employee department: ";
                    getline(cin, emp.department);
                  
                    employees[count] = emp;
                    count++;
                    cout << "Employee added successfully!" << endl;
                } else {
                    cout << "Maximum employee limit reached!" << endl;
                }
                break;

            case 2:
                if (count > 0) {
                    cout << "Employee List:" << endl;
                    for (int i = 0; i < count; i++) {
                        cout << "ID: " << employees[i].id << endl;
                        cout << "Name: " << employees[i].name << endl;
                        cout << "Department: " << employees[i].department << endl;
                        cout << endl;
                    }
                } else {
                    cout << "No employees found!" << endl;
                }
                break;

            case 3:
                int searchId;
                cout << "Enter employee ID to search: ";
                cin >> searchId;
                for (int i = 0; i < count; i++) {
                    if (employees[i].id == searchId) {
                        cout << "Employee found:" << endl;
                        cout << "ID: " << employees[i].id << endl;
                        cout << "Name: " << employees[i].name << endl;
                        cout << "Department: " << employees[i].department << endl;
                        break;
                    }
                    if (i == count - 1) {
                        cout << "Employee not found!" << endl;
                    }
                }
                break;

            case 4:
                int updateId;
                cout << "Enter employee ID to update: ";
                cin >> updateId;
                for (int i = 0; i < count; i++) {
                    if (employees[i].id == updateId) {
                        cout << "Enter updated employee name: ";
                        cin.ignore(); // Ignore the newline character
                        getline(cin, employees[i].name);
                        cout << "Enter updated employee department: ";
                        getline(cin, employees[i].department);
                        cout << "Employee details updated successfully!" << endl;
                        break;
                    }
                    if (i == count - 1) {
                        cout << "Employee not found!" << endl;
                    }
                }
                break;

            case 5:
                int deleteId;
                cout << "Enter employee ID to delete: ";
                cin >> deleteId;
                for (int i = 0; i < count; i++) {
                    if (employees[i].id == deleteId) {
                        for (int j = i; j < count - 1; j++) {
                            employees[j] = employees[j + 1];
                        }
                        count--;
                        cout << "Employee deleted successfully!" << endl;
                        break;
                    }
                    if (i == count - 1) {
                        cout << "Employee not found!" << endl;
                    }
                }
                break;

            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
