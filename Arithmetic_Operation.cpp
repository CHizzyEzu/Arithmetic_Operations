// Creating a menu that gives the user a choice between multiple different arthmetic values 


#include <iostream>
#include <iomanip>
#include <fstream>  
#include <limits>
#include <string>
using namespace std;

int main()
{
    string yourname; // Name the file with user name

    // Initialize variables that hold arthmetic solutions
    int additionCount = 0, subtractionCount = 0, multiplicationCount = 0, divisionCount = 0, moduloCount = 0, totalCount = 0;
    int num1, num2, choice; // values user inputs

    cout << "Enter your name: ";
    getline(cin >> ws, yourname); 

    std::ofstream outputFile; // file opens
    outputFile.open(yourname + ".txt"); 

    // Loop for user data 
    while (true)
    {
        cout << "Enter first number (-1 to exit): ";
        if(!(cin >> num1))
        {
            cout << "Invalid input. Please input a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if(num1 == -1) 
            break;

        cout << "Enter second number: ";
        if(!(cin >> num2))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Menu 
        cout << " Choose an operation: \n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5 Modulo\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu arithmetic choices 
        switch (choice)     
        {
            case 1:
                cout << "Result: " << num1 + num2 << endl;
                additionCount++;
            break;

            case 2:
                cout << "Result: " << num1 - num2 << endl;
                subtractionCount++;
            break; 

            case 3:
                cout << "Result: " << num1 * num2 << endl;
                multiplicationCount++;
                break;

            case 4:
                if (num2 != 0)
                {
                    cout << "Result: " << num1 / num2 << endl;
                }
                else
                {
                    cout << " Error: Division by zero!" << endl;
                }
                divisionCount++;
                break;

            case 5: 
                cout << "Result: " << num1 % num2 << endl;
                moduloCount++;
                break;

            default: // User validation to input only the selcted options
            cout << "Invalid choice. Please enter a number between 1 - 5." << endl;
        }      

        totalCount++; // Keeps track of choices made
    }

    // Output of the arthmetic chosen and the amount of times the options were used
    cout << "Addition: " << additionCount << endl;
    cout << "Subtraction: " << subtractionCount << endl;
    cout << "Multiplication: " << multiplicationCount << endl;
    cout << "Division: " << divisionCount << endl;
    cout << "Modulo: " << moduloCount << endl;
    cout << "Total: " << totalCount << endl;

    // Writing output to file
    outputFile << "Addition: " << additionCount << endl;
    outputFile << "Subtraction: " << subtractionCount << endl;
    outputFile << "Multiplication: " << multiplicationCount << endl;
    outputFile << "Division: " << divisionCount << endl;
    outputFile << "Modulo: " << moduloCount << endl;
    outputFile << "Total: " << totalCount << endl;

    outputFile.close();

    return 0;
}