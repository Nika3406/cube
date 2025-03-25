// Virtual Assistant V2.0 (VEGA)
// Nicholas Shvelidze, Mariami Shinjiashvili

#include <iostream>
#include <thread>
#include <chrono>
#include "basicMath.cpp"
#include "advancedMath.cpp"
#include "dataSets.cpp"
#include "converter.cpp"
#include "games.cpp"
#include "ascii_fps.cpp"
 
using namespace std;

void displayTitle()
{
    cout << "\n";
    cout << " _    _   ______    ____     ____ \n";
    cout << "| |  | | |  ____| /  __  \\ /  __  \\ \n";
    cout << "| |  | | | |__    | |  |_| | |  | |\n";
    cout << "| |  | | |  __|   | |   __ | |__| |\n";
    cout << "| |__| | | |____  | |__| _||  __  |\n";
    cout << " \\____/  |______| |_____/  |_|  |_|\n";
    cout << "\n";
}

void virtualAssistant()
{
    int operation;
    do 
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Basic Math Operations\n";
        cout << "2. Advanced Math Operations\n";
        cout << "3. Data Sets\n";
        cout << "4. Converter\n";
        cout << "5. Games\n";
		cout << "6. FPS Simulation\n";
        cout << "7. Exit to Main Menu\n";
        cin >> operation;

        switch (operation) 
        {
            case 1: 
                basicMathOperations();
                break;
            case 2: 
                advancedMathOperations();
                break;
        	case 3:
        		dataPredictor();
        		break;
            case 4: 
                converter();
                break;
            case 5:
                games();
                break;
            case 6: 
                {
                    cout << "Use W/A/S/D to move. Press SPACE to exit.\n";

                    bool running = true;
                    while (running) {
                        render();
                        this_thread::sleep_for(chrono::milliseconds(2));
						running = update();
                    }
                    break;
                }
            case 7: 
                cout << "Returning to main menu...\n";
                break;
            default: 
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } 
    while (operation != 7);
}

int main() 
{
    int choice;
    do 
    {
        displayTitle();
        cout << "\nHello, I am VEGA, your Virtual Assistant." << endl;
        cout << "Choose an option:\n";
        cout << "1. Start Virtual Assistant\n";
        cout << "2. Exit Program\n";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
                virtualAssistant();
                break;
            case 2:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } 
    while (choice != 2);

    return 0;
}
