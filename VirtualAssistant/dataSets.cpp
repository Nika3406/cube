#include <iostream>
#include <cmath>

using namespace std;

void dataPredictor()
{
	double numbers[20];
	
    cout << "Enter 20 numbers: " << endl;
    for (int i = 0; i < 20; i++) 
	{
        cin >> numbers[i];
    }
    
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < 20; i++) 
	{
        sumX += i;
        sumY += numbers[i];
        sumXY += i * numbers[i];
        sumX2 += i * i;
    }
    
    double slope = (20 * sumXY - sumX * sumY) / (20 * sumX2 - sumX * sumX);
    double intercept = (sumY - slope * sumX) / 20;
    
    cout << "Predicted next 5 numbers: " << endl;
    for (int i = 20; i < 25; i++) 
	{
        double prediction = slope * i + intercept;
        cout << prediction << " ";
    }
    cout << endl;
}