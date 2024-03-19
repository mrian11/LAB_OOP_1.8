///////////////////////////////////////////////////////
// main.cpp
#include "Fraction.h"
#include<iostream>

using namespace std;

void displayMenu() {
    cout << "1. Enter the first number\n";
    cout << "2. Display the first number\n";
    cout << "3. Add two numbers\n";
    cout << "4. Subtract two  numbers\n";
    cout << "5. Multiply two  numbers\n";
    cout << "6. Stirng\n";
    cout << "7. Rivne\n";
    cout << "8. Ne rivne\n";
    cout << "9. Bilshe\n";
    cout << "10. Menshe\n";
    cout << "11. Menshe-rivne\n";
    cout << "11. Bilshe-rivne\n";
    cout << "13. PAPA\n";
    cout << "Enter your choice: ";
}

int main()
{
    Fraction frac1, frac2, result;


    //frac1.Init();
    //frac2.Read();


    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            frac1.Read();
            break;
        case 2:
            cout << "Entered complex number: ";
            frac1.Display();
            break;
        case 3:
            frac2.Read();
            result = frac1 + (frac2);
            cout << "Sum: ";
            result.Display();
            break;
        case 4:
            frac2.Read();
            result = frac1 - (frac2);
            cout << "Difference: ";
            result.Display();
            break;
        case 5:
            frac2.Read();
            result = frac1 * (frac2);
            cout << "Product: ";
            result.Display();
            break;
        case 6:
            cout << "String representation: " << frac1.toString() << endl;
            break;
        case 7:
            frac2.Read();
            if (frac1 == frac2) {
                cout << "\nGoood.";
            }
            else {
                cout << "\nNOOOO";
            }
            result.Display();
            break;
        case 8:

            frac2.Read();
            if (frac1 != frac2) {
                cout << "\nGoood.";
            }
            else {
                cout << "\nNOOOO";
            }
            result.Display();
            break;
        case 9:
            frac2.Read();
            if (frac1 < frac2) {
                cout << "\nGoood.";
            }
            else {
                cout << "\nNOOOO";
            }
            result.Display();
            break;
        case 10:

            frac2.Read();
            if (frac1 > frac2) {
                cout << "\nGoood.";
            }
            else {
                cout << "\nNOOOO";
            }
            result.Display();
            break;
        case 11:
            frac1.Read();
            if (frac1 <= frac2) {
                cout << "\nGoood.";
            }
            else {
                cout << "\nNOOOO";
            }
            result.Display();
            break;
        case 12:
            frac2.Read();
            if (frac1 >= frac2) {
                cout << "\nGoood.";
            }
            else {
                cout << "\nNOOOO";
            }
            result.Display();
            break;
        case 13:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 13);
    return 0;
}