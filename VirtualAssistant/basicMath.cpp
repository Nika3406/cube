#include <iostream>
#include <cmath>

using namespace std;

void add() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Addition: " << num1 + num2 << endl;
}

void subtract() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Subtraction: " << num1 - num2 << endl;
}

void multiply() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Multiplication: " << num1 * num2 << endl;
}

void divide() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    if (num2 != 0)
        cout << "Division: " << num1 / num2 << endl;
    else
        cout << "Division by zero is not allowed." << endl;
}

void average() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Average: " << (num1 + num2) / 2 << endl;
}

void checkEvenOdd() 
{
    double num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Number is " << ((static_cast<int>(num) % 2 == 0) ? "Even" : "Odd") << endl;
}

void checkSign() 
{
    double num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Number is " << (num > 0 ? "Positive" : (num < 0 ? "Negative" : "Zero")) << endl;
}

void squareRoot() 
{
    double num;
    cout << "Enter a number: ";
    cin >> num;
    if (num >= 0)
        cout << "Square root: " << sqrt(num) << endl;
    else
        cout << "Cannot compute square root of a negative number." << endl;
}

void absoluteValue() 
{
    double num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Absolute Value: " << fabs(num) << endl;
}

void switchnums() {
    double num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    double temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "After swapping:\n";
    cout << "First number: " << num1 << endl;
    cout << "Second number: " << num2 << endl;
}

void minMaxNums()
{
    double a,b,c;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "Enter third number: ";
    cin >> c;
    cout << "The min value is " << min(a, min(b,c)) << endl;
    cout << "The max value is " << max(a, max(b,c)) << endl;
}


void basicMathOperations() 
{
    int operation;
    do 
    {
        cout << "Choose an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Average\n6. Check Even or Odd\n7. Check Sign (Positive/Negative)\n8. Square Root\n9. Absolute Value\n10. Switch Numbers\n11. Minumum/Maximum Number\n12. Exit" << endl;
        cin >> operation;

        switch (operation) 
        {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: average(); break;
            case 6: checkEvenOdd(); break;
            case 7: checkSign(); break;
            case 8: squareRoot(); break;
            case 9: absoluteValue(); break;
            case 10: switchnums(); break;
            case 11: minMaxNums(); break;
            case 12: cout << "Exiting Program"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } 
    while (operation != 12);
}
