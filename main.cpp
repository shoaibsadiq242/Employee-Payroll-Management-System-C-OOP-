#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int empID;
    string name;
    float basicSalary;
    float allowance;
    float deduction;

public:
    Employee() {
        empID = 0;
        name = "";
        basicSalary = 0;
        allowance = 0;
        deduction = 0;
    }

    void setID(int id) {
        empID = id;
    }

    void inputDetails() {
        cin.ignore(); // flush newline
        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        cout << "Enter Allowance: ";
        cin >> allowance;

        cout << "Enter Deduction: ";
        cin >> deduction;
    }

    int getID() {
        return empID;
    }

    float calculateNetSalary() {
        return basicSalary + allowance - deduction;
    }

    void displayEmployee() {
        cout << "\n------------------------------\n";
        cout << "Employee ID     : " << empID << endl;
        cout << "Name            : " << name << endl;
        cout << "Basic Salary    : " << basicSalary << endl;
        cout << "Allowance       : " << allowance << endl;
        cout << "Deduction       : " << deduction << endl;
        cout << "Net Salary      : " << calculateNetSalary() << endl;
        cout << "------------------------------\n";
    }
};

int main() {
    int capacity = 2;
    Employee* employees = new Employee[capacity];
    int count = 0;

    int choice;

    cout << "===== EMPLOYEE PAYROLL SYSTEM =====\n";

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Edit Employee\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\nExiting program. Goodbye!\n";
            break;
        }

        else if (choice == 1) {
            int newID;
            cout << "\nEnter Employee ID: ";
            cin >> newID;

            // Check for unique ID BEFORE asking for other details
            bool idExists = false;
            for (int i = 0; i < count; i++) {
                if (employees[i].getID() == newID) {
                    cout << "\nEmployee ID already exists! Try again with a different ID.\n";
                    idExists = true;
                    break;
                }
            }
            if (idExists) continue; // stop adding immediately

            // Resize array if needed
            if (count >= capacity) {
                int newCapacity = capacity * 2;
                Employee* temp = new Employee[newCapacity];
                for (int i = 0; i < count; i++) {
                    temp[i] = employees[i];
                }
                delete[] employees;
                employees = temp;
                capacity = newCapacity;
                cout << "\nEmployee storage expanded to " << capacity << " slots.\n";
            }

            // Now input the rest of the employee details
            Employee newEmp;
            newEmp.setID(newID);
            newEmp.inputDetails();
            employees[count] = newEmp;
            count++;
            cout << "\nEmployee added successfully!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "\nNo employees available.\n";
            }
            else {
                for (int i = 0; i < count; i++) {
                    employees[i].displayEmployee();
                }
            }
        }

        else if (choice == 3) {
            if (count == 0) {
                cout << "\nNo employees available.\n";
            }
            else {
                int id;
                cout << "\nEnter Employee ID to search: ";
                cin >> id;

                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (employees[i].getID() == id) {
                        cout << "\nEmployee Found!\n";
                        employees[i].displayEmployee();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nEmployee not found.\n";
                }
            }
        }

        else if (choice == 4) {
            if (count == 0) {
                cout << "\nNo employees available.\n";
            }
            else {
                int id;
                cout << "\nEnter Employee ID to edit: ";
                cin >> id;

                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (employees[i].getID() == id) {
                        cout << "\nEditing Employee ID " << id << ":\n";
                        employees[i].inputDetails();
                        cout << "\nEmployee details updated successfully!\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "\nEmployee not found.\n";
                }
            }
        }

        else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }

    delete[] employees;
    return 0;
}
