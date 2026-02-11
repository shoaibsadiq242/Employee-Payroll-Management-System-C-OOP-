# Employee Payroll System (OOP - C++)

A console-based Employee Payroll Management System developed using Object-Oriented Programming (OOP) concepts in C++. This project allows users to add, search, edit, and display employee records while automatically calculating net salary.

---

## 📌 Project Overview

This system manages employee data dynamically using classes and dynamic memory allocation. Each employee has a unique ID and salary details including allowance and deduction. The program ensures ID uniqueness before adding a new employee.

---

## 🚀 Features

* Add new employees with unique ID validation
* View all employee records
* Search employee by ID
* Edit employee details
* Automatic Net Salary Calculation
* Dynamic memory resizing when capacity is exceeded
* Menu-driven interactive console interface

---

## 🏗️ OOP Concepts Used

* Class and Objects
* Encapsulation (private data members with public functions)
* Constructors
* Member functions
* Dynamic memory allocation using `new` and `delete`

---

## 🧮 Salary Calculation

Net Salary is calculated using the formula:

Net Salary = Basic Salary + Allowance - Deduction

---

## 🛠️ How to Run

```bash
# Compile the program
g++ main.cpp -o payroll

# Run the program
./payroll        # Linux / Mac
payroll.exe      # Windows
```

---

## 📋 How It Works

1. The program starts with an initial employee storage capacity.
2. Users can select operations from the menu.
3. When adding an employee:

   * The system first checks if the ID already exists.
   * If storage is full, capacity is automatically doubled.
4. Employees can be searched or edited using their unique ID.
5. The program runs continuously until the user chooses to exit.

---

## 📂 Project Structure

* `main.cpp` – Contains the Employee class and complete program logic.

---

## 🎯 Learning Outcome

This project demonstrates practical implementation of OOP principles and dynamic memory handling in C++ through a real-world payroll management scenario.

---

## 📄 License

This project is created for educational purposes and personal practice.

---

## 👨‍💻 Author

Malik Shoaib – BS Software Engineering Student
