/*
==========================================================
  ELECTRICITY MANAGEMENT SYSTEM
  Sir Syed University of Engineering and Technology (SSUET)
  Subject: Introduction to Programming (C++)
  Semester Project - Beginner Level
==========================================================
  C++ Concepts Used:
  - Variables & Built-in Data Types (int, double, string, char)
  - Input/Output (cin, cout)
  - Conditional Statements (if, else if, else)
  - User Defined Functions
  - Built-in Functions (from <string>, <iomanip>)
==========================================================
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// -------------------------------------------------------
// FUNCTION 1: login()
// This function checks username and password.
// Returns true if correct, otherwise false.
// -------------------------------------------------------
bool login() {
    string correctUsername = "admin";
    string correctPassword = "ssuet123";

    string enteredUsername;
    string enteredPassword;

    cout << "\n========================================" << endl;
    cout << "   ELECTRICITY MANAGEMENT SYSTEM" << endl;
    cout << "   K-Electric Style Billing Portal" << endl;
    cout << "========================================" << endl;
    cout << "\n--- LOGIN PAGE ---" << endl;

    cout << "Enter Username: ";
    cin >> enteredUsername;

    cout << "Enter Password: ";
    cin >> enteredPassword;

    if (enteredUsername == correctUsername && enteredPassword == correctPassword) {
        cout << "\n✓ Login Successful! Welcome!" << endl;
        return true;
    } else {
        cout << "\n✗ Invalid Username or Password! Access Denied." << endl;
        return false;
    }
}

// -------------------------------------------------------
// FUNCTION 2: calculateUnits()
// Calculates units consumed from current and previous
// meter readings.
// -------------------------------------------------------
double calculateUnits(double currentReading, double previousReading) {
    double unitsConsumed = currentReading - previousReading;

    if (unitsConsumed < 0) {
        cout << "Error: Current reading cannot be less than previous reading!" << endl;
        return 0;
    }

    return unitsConsumed;
}

// -------------------------------------------------------
// FUNCTION 3: calculateBill()
// Calculates electricity bill according to slab rates.
// -------------------------------------------------------
double calculateBill(double units) {
    double billAmount = 0;
    double gstRate = 0.17;
    double fixedCharges = 75.0;

    if (units <= 100) {
        billAmount = units * 3.95;
    } else if (units <= 200) {
        billAmount = (100 * 3.95) + ((units - 100) * 7.74);
    } else if (units <= 300) {
        billAmount = (100 * 3.95) + (100 * 7.74) + ((units - 200) * 10.06);
    } else if (units <= 400) {
        billAmount = (100 * 3.95) + (100 * 7.74) + (100 * 10.06) +
                     ((units - 300) * 12.15);
    } else {
        billAmount = (100 * 3.95) + (100 * 7.74) + (100 * 10.06) +
                     (100 * 12.15) + ((units - 400) * 19.71);
    }

    double gstAmount = billAmount * gstRate;
    double totalBill = billAmount + gstAmount + fixedCharges;

    return totalBill;
}

// -------------------------------------------------------
// FUNCTION 4: displayBill()
// Displays customer details and bill breakdown.
// -------------------------------------------------------
void displayBill(string customerName, string meterNumber,
                 double prevReading, double currReading,
                 double units, double totalBill) {

    cout << "\n========================================" << endl;
    cout << "       K-ELECTRIC BILL STATEMENT" << endl;
    cout << "========================================" << endl;
    cout << fixed << setprecision(2);

    cout << "Customer Name   : " << customerName << endl;
    cout << "Meter Number    : " << meterNumber << endl;
    cout << "Previous Reading: " << prevReading << " kWh" << endl;
    cout << "Current Reading : " << currReading << " kWh" << endl;
    cout << "Units Consumed  : " << units << " kWh" << endl;
    cout << "----------------------------------------" << endl;

    double baseAmount = 0;

    if (units <= 100) {
        baseAmount = units * 3.95;
        cout << "Slab Rate       : Rs. 3.95/unit (0-100)" << endl;
    } else if (units <= 200) {
        baseAmount = (100 * 3.95) + ((units - 100) * 7.74);
        cout << "Slab Rate       : Multiple slabs applied" << endl;
    } else if (units <= 300) {
        baseAmount = (100 * 3.95) + (100 * 7.74) +
                     ((units - 200) * 10.06);
        cout << "Slab Rate       : Multiple slabs applied" << endl;
    } else if (units <= 400) {
        baseAmount = (100 * 3.95) + (100 * 7.74) +
                     (100 * 10.06) + ((units - 300) * 12.15);
        cout << "Slab Rate       : Multiple slabs applied" << endl;
    } else {
        baseAmount = (100 * 3.95) + (100 * 7.74) +
                     (100 * 10.06) + (100 * 12.15) +
                     ((units - 400) * 19.71);
        cout << "Slab Rate       : Multiple slabs applied" << endl;
    }

    double gstAmount = baseAmount * 0.17;
    double fixedCharges = 75.0;

    cout << "Energy Charges  : Rs. " << baseAmount << endl;
    cout << "GST (17%)       : Rs. " << gstAmount << endl;
    cout << "Fixed Charges   : Rs. " << fixedCharges << endl;
    cout << "----------------------------------------" << endl;
    cout << "TOTAL BILL      : Rs. " << totalBill << endl;
    cout << "========================================" << endl;
}

// -------------------------------------------------------
// FUNCTION 5: paymentStatus()
// Displays payment status.
// -------------------------------------------------------
void paymentStatus(double totalBill, double paymentAmount) {

    cout << "\n--- PAYMENT STATUS ---" << endl;
    cout << fixed << setprecision(2);

    cout << "Total Bill      : Rs. " << totalBill << endl;
    cout << "Amount Paid     : Rs. " << paymentAmount << endl;

    if (paymentAmount >= totalBill) {

        double change = paymentAmount - totalBill;

        cout << "Status          : ✓ PAID" << endl;

        if (change > 0) {
            cout << "Change Return   : Rs. " << change << endl;
        }

        cout << "Thank You! Payment received successfully." << endl;

    } else if (paymentAmount > 0 && paymentAmount < totalBill) {

        double remaining = totalBill - paymentAmount;

        cout << "Status          : ⚠ PARTIALLY PAID" << endl;
        cout << "Remaining Amount: Rs. " << remaining << endl;
        cout << "Please pay the remaining amount soon to avoid disconnection."
             << endl;

    } else {

        cout << "Status          : ✗ UNPAID" << endl;
        cout << "Please pay the full bill to avoid a disconnection notice."
             << endl;
    }

    cout << "========================================" << endl;
}

// -------------------------------------------------------
// MAIN FUNCTION
// Program execution starts here.
// -------------------------------------------------------
int main() {

    bool loginSuccess = login();

    if (!loginSuccess) {
        cout << "Program is closing..." << endl;
        return 0;
    }

    string customerName;
    string meterNumber;
    double previousReading;
    double currentReading;
    double paymentAmount;

    cout << "\n--- CUSTOMER INFORMATION ---" << endl;

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Enter Meter Number: ";
    cin >> meterNumber;

    cout << "Enter Previous Meter Reading (kWh): ";
    cin >> previousReading;

    cout << "Enter Current Meter Reading (kWh): ";
    cin >> currentReading;

    double unitsConsumed =
        calculateUnits(currentReading, previousReading);

    if (unitsConsumed == 0 && currentReading < previousReading) {
        cout << "Program is closing..." << endl;
        return 0;
    }

    double totalBill = calculateBill(unitsConsumed);

    displayBill(customerName, meterNumber,
                previousReading, currentReading,
                unitsConsumed, totalBill);

    cout << "\n--- PAYMENT SECTION ---" << endl;
    cout << "Enter Payment Amount (Rs.): ";
    cin >> paymentAmount;

    paymentStatus(totalBill, paymentAmount);

    cout << "\nProgram completed successfully!" << endl;
    cout << "SSUET - Introduction to Programming Semester Project" << endl;

    return 0;
}