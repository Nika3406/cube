#include <iostream>
#include <map>

using namespace std;

void currencyConversion() 
{
    map<int, string> currencies = {
        {1, "USD"}, {2, "EUR"}, {3, "JPY"}, {4, "GBP"}, {5, "AUD"},
        {6, "CAD"}, {7, "CHF"}, {8, "CNH"}, {9, "HKD"}, {10, "NZD"}
    };

    // Base exchange rates relative to USD 
    map<int, double> baseRates = {
        {1, 1.0}, {2, 0.92}, {3, 150.0}, {4, 0.78}, {5, 1.52}, 
        {6, 1.36}, {7, 0.91}, {8, 7.25}, {9, 7.82}, {10, 1.61}
    };

    int fromCurrency, toCurrency;
    double currencyAmount;
    
    cout << "Select your current currency:" << endl;
    for (const auto &c : currencies)
        cout << c.first << ") " << c.second << endl;
    cin >> fromCurrency;

    cout << "Select the currency to convert to:" << endl;
    for (const auto &c : currencies)
        cout << c.first << ") " << c.second << endl;
    cin >> toCurrency;

    if (currencies.count(fromCurrency) == 0 || currencies.count(toCurrency) == 0)
    {
        cout << "Invalid currency selection!" << endl;
        return;
    }

    cout << "Enter amount in " << currencies[fromCurrency] << ": ";
    cin >> currencyAmount;

    if (fromCurrency == toCurrency)
    {
        cout << "Converted amount: " << currencyAmount << " " << currencies[toCurrency] << endl;
        return;
    }

    // Convert to USD as an intermediary, then to target currency
    double amountInUSD = currencyAmount / baseRates[fromCurrency];
    double converted = amountInUSD * baseRates[toCurrency];

    cout << "Converted amount: " << converted << " " << currencies[toCurrency] << endl;
}

void lengthConversion() 
{
    map<int, string> lengthUnits = 
    {
        {1, "Inch"}, {2, "Foot"}, {3, "Yard"}, {4, "Mile"}, {5, "Centimeter"}, {6, "Meter"}, {7, "Kilometer"}
    };

    // Base conversion rates relative to meters 
    map<int, double> baseRates = 
    {
        {1, 0.0254}, {2, 0.3048}, {3, 0.9144}, {4, 1609.34}, {5, 0.01}, {6, 1.0}, {7, 1000.0}   
    };

    int fromUnit, toUnit;
    double lengthAmount;
    
    cout << "Select your current length unit:" << endl;
    for (const auto &l : lengthUnits)
        cout << l.first << ") " << l.second << endl;
    cin >> fromUnit;
    
    cout << "Select the length unit to convert to:" << endl;
    for (const auto &l : lengthUnits)
        cout << l.first << ") " << l.second << endl;
    cin >> toUnit;
    
    if (lengthUnits.count(fromUnit) == 0 || lengthUnits.count(toUnit) == 0)
    {
        cout << "Invalid unit selection!" << endl;
        return;
    }
    
    cout << "Enter amount in " << lengthUnits[fromUnit] << ": ";
    cin >> lengthAmount;
    
    if (fromUnit == toUnit)
    {
        cout << "Converted amount: " << lengthAmount << " " << lengthUnits[toUnit] << endl;
        return;
    }

    // Convert to meters as an intermediary, then to target unit
    double amountInMeters = lengthAmount * baseRates[fromUnit];
    double converted = amountInMeters / baseRates[toUnit];

    cout << "Converted amount: " << converted << " " << lengthUnits[toUnit] << endl;
}

void speedConversion() 
{
    map<int, string> speedUnits = 
    {
        {1, "m/s"}, {2, "km/h"}, {3, "mph"}, {4, "ft/s"}, {5, "kn"} 
    };

    // Base conversion rates relative to meters per second (m/s)
    map<int, double> baseRates = 
    {
        {1, 1.0}, {2, 0.277778}, {3, 0.44704}, {4, 0.3048}, {5, 0.514444}
    };

    int fromUnit, toUnit;
    double speedAmount;
    
    cout << "Select your current speed unit:" << endl;
    for (const auto &s : speedUnits)
        cout << s.first << ") " << s.second << endl;
    cin >> fromUnit;
    
    cout << "Select the speed unit to convert to:" << endl;
    for (const auto &s : speedUnits)
        cout << s.first << ") " << s.second << endl;
    cin >> toUnit;
    
    if (speedUnits.count(fromUnit) == 0 || speedUnits.count(toUnit) == 0)
    {
        cout << "Invalid unit selection!" << endl;
        return;
    }
    
    cout << "Enter speed in " << speedUnits[fromUnit] << ": ";
    cin >> speedAmount;
    
    if (fromUnit == toUnit)
    {
        cout << "Converted speed: " << speedAmount << " " << speedUnits[toUnit] << endl;
        return;
    }

    // Convert to meters per second (m/s) as an intermediary, then to target unit
    double speedInMetersPerSecond = speedAmount * baseRates[fromUnit];
    double converted = speedInMetersPerSecond / baseRates[toUnit];

    cout << "Converted speed: " << converted << " " << speedUnits[toUnit] << endl;
}

void converter()
{
    int operation;
    do 
    {
        cout << "Choose an operation:\n1. Currency Conversion\n2. Length Conversion\n3. Speed Conversion\n4. Exit" << endl;
        cin >> operation;

        switch (operation) 
        {
            case 1: currencyConversion(); break;
            case 2: lengthConversion(); break;
            case 3: speedConversion(); break;
            case 4: cout << "Exiting Program"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } 
    while (operation != 4);
}