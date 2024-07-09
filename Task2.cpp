#include<iostream>

using namespace std;

int main() {
    double n1,n2;
    char o;

    cout << "Welcome To Simple Calculator!" << endl;
    cout << "Enter the First Number To Perform Operations: ";
    cin >> n1;
    cout << "Enter the Second Number To Perform Operations: ";
    cin >> n2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> o;

    switch (o) {
        case '+':
            cout << "Result: " << n1 + n2<< endl;
            break;
        case '-':
            cout << "Result: " << n1 - n2 << endl;
            break;
        case '*':
            cout << "Result: " << n1 * n2 << endl;
            break;
        case '/':
            if (n2 == 0) {
                cout << "Error: Division by zero is not possible." << endl;
            } else {
                cout << "Result: " << n1 / n2 << endl;
            }
            break;
        default:
            cout << "Operation does not exist in this calculator .Please choose a valid operation." << endl;
    }

    return 0;
}