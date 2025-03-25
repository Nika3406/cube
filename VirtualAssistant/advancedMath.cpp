#include <iostream>
#include <cmath>

using namespace std;

void perimeter() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Perimeter of Quadrilateral: " << 2 * (num1 + num2) << endl;
}

void area() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Area of Quadrilateral: " << num1 * num2 << endl;
}

void multiplicationTableN() 
{
    int n;
    
    cout << "Enter number: " << endl;
    
    cin >> n;
    
    cout << "Multiplication Table of n:" << endl;
    for (int i = 1; i <= 12; i++) 
    {
        cout << n << " x " << i << " = " << n * i << endl;
    }
} 

void hypotenuse() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Hypotenuse: " << sqrt(num1 * num1 + num2 * num2) << endl;
}


void quadFormula()
{
    double a, b, c, x1, x2, discriminant;
    
    cout << "Quadratic Equation:" << endl;
    cout << "Enter two numbers: " << endl;
    
    cin >> a >> b >> c;
    
    discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        cout << "root 1: " << x1 << endl;
        
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "root 2: " << x2 << endl;
    }
    else if (discriminant == 0) 
    {
        x1 = -b / (2 * a);
        cout << "One real double root: " << x1 << endl;
    }
    else if (discriminant < 0)
    {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "complex root 1: " << realPart << " + " << imaginaryPart << "i" << endl; 
        cout << "complex root 2: " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

void sumSquares()
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "Sum of Squares: " << ( (num1 * num1) + (num2 * num2) ) << endl;
}

void sumN() 
{
    cout << "How many Integers you want to go up to" << endl;
	int n;
    cin >> n;
    
    int j = 0;   
    for (int i = 0; i <= n; i++)
    {
        j += i;
    }
    cout << "Sum of First " << n << " integers is: " << j << endl;

}

void sumEvenN() 
{
    cout << "How many Even Integers you want to go up to" << endl;
	int n;
    cin >> n;
    int j = 0;
    for (int i = 0; i <= n; i++) 
	{
        if ((i%2) == 0) 
		{
            j += i;
        }
    }
    cout << "Sum of First " << n << " even integers is: " << j << endl;
}

void firstDegree()
{
    double a, b, c;
	cout << "Enter value for a: " << endl;
    cin >> a;
    cout << "Enter value for b: " << endl;
    cin >> b;
    cout << "Enter value for c: " << endl;
    cin >> c;
	double f = c-b;
    double x = f/a;
    cout << "The value of x is " << x << endl;
}

void advancedMathOperations() 
{
    int operation;
    do 
    {
        cout << "Choose an operation:\n1. Perimeter of Quadrilateral\n2. Area of Quadrilateral\n3. Multiplication Table\n4. Hypotenuse (a^2 + b^2 = c^2)\n5. First Degree Equation (ax + b = c)\n6. Quadratic Formula (ax^2 + bx + c = 0)\n7. Sum of Squares\n8. Sum of N Integers\n9. Sum of N Even Integers\n10. Exit" << endl;
        cin >> operation;

        switch (operation) 
        {
            case 1: perimeter(); break;
            case 2: area(); break;
            case 3: multiplicationTableN(); break;
            case 4: hypotenuse(); break;
            case 5: firstDegree(); break;
            case 6: quadFormula(); break;
            case 7: sumSquares(); break;
            case 8: sumN(); break;
            case 9: sumEvenN(); break;
            case 10: cout << "Exiting Program"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } 
    while (operation != 10);
}
