#include "user_interface.h"
#include "utilities.h"
#include "calculator.h"
#include <iostream>
#include <string>
using namespace std;

void UserInterface::run()
{
    displayIntro();
    handleUserInput();
    getCompoundInterestandBalance();
    displayInvestmentGrowthChart();
}

void UserInterface::displayIntro()
{
    Utilities::clearScreen();
    cout << Utilities::alternatingCharString('*', ' ', width+2) << endl;
    cout << Utilities::centerString("Welcome to Airgead Banking", 50) << endl;
    cout << Utilities::repeatingCharString('=', width+1) << endl;
    cout << Utilities::centerString("This application demonstrates how investments ", width) << endl;
    cout<< Utilities::centerString("can grow over time with compound interest.", width) << endl;
    cout << endl;
    cout << Utilities::centerString("You can enter your initial investment, ", width) << endl; 
    cout << Utilities::centerString("optional monthly deposits, annual interest rate, ", width) << endl; 
    cout<< Utilities::centerString("and the number of years to invest.", width) << endl;
    cout << endl;
    cout << Utilities::centerString("Let's get started!", width) << endl << endl;
    cout << Utilities::alternatingCharString('*', ' ', width+2) << endl;
}

void UserInterface::handleUserInput()
{
    string input;
    double initialInvestment = 0.0;
    double monthlyDeposit = 0.0;
    bool automaticMonthlyDeposit = false;
    double annualInterestRate = 0.0;
    int numberOfYears = 0;

    // Get Initial Investment
    do {
        cout << "Enter Initial Investment Amount (positive number): ";
        getline(cin, input);
        if (!Utilities::isValidPositiveDouble(input)) {
            cout << "Invalid input. Please enter a positive number." << endl;
        } else {
            initialInvestment = Utilities::stringToDouble(input);
        }
    } while (initialInvestment <= 0);

    cout << "Would you like to make automatic monthly deposits? (y/n): ";
    getline(cin, input);
    if (input == "y" || input == "Y") {
        automaticMonthlyDeposit = true;
        // Get Monthly Deposit
        do {
            cout << "Enter Monthly Deposit Amount (positive number or zero by default): ";
            getline(cin, input);
            if (!Utilities::isValidPositiveDouble(input)) {
                cout << "Invalid input. Please enter a positive number." << endl;
            } else {
                monthlyDeposit = Utilities::stringToDouble(input);
            }
        } while (monthlyDeposit < 0); // Monthly deposit can be zero
    }
    else {
        automaticMonthlyDeposit = false;

    }

    // Get Annual Interest Rate
    do {
        cout << "Enter Annual Interest Rate (as a percentage, e.g., 5 for 5%): ";
        getline(cin, input);
        if (!Utilities::isValidPositiveDouble(input)) {
            cout << "Invalid input. Please enter a positive number." << endl;
        } else {
            annualInterestRate = Utilities::stringToDouble(input);
        }
    } while (annualInterestRate <= 0);

    // Get Number of Years
    do {
        cout << "Enter Number of Years to Invest (positive integer): ";
        getline(cin, input);
        if (!Utilities::isValidPositiveInt(input)) {
            cout << "Invalid input. Please enter a positive integer." << endl;
        } else {
            numberOfYears = Utilities::stringToInt(input);
        }
    } while (numberOfYears <= 0);

    // Clear the screen before displaying results
    Utilities::clearScreen();

    // Display the collected inputs for confirmation
    cout << Utilities::repeatingCharString('=', width) << endl;
    cout << Utilities::centerString("Investment Details", 50) << endl;
    cout << Utilities::repeatingCharString('=', width) << endl;
    cout << "Initial Investment Amount: " << Utilities::formatCurrency(initialInvestment) << endl;
    cout << "Monthly Deposit Amount: " << Utilities::formatCurrency(monthlyDeposit) << endl;
    cout << "Annual Interest Rate: " << Utilities::formatPercentage(annualInterestRate / 100) << endl;
    cout << "Number of Years to Invest: " << numberOfYears << endl << endl;    
    cout << Utilities::alternatingCharString('*', ' ', width+2) << endl;   
    cout << "Press 'enter' to continue, 'c' to make changes, " << endl;
    cout<< " or 'q' to quit." << endl;
   

    if (cin.peek() == 'q' || cin.peek() == 'Q') {
        cout << Utilities::repeatingCharString('=', 50) << endl;
        cout << Utilities::centerString("Thank you for using Airgead Banking!", width) << endl;
        cout << Utilities::alternatingCharString('*', ' ', width+2) << endl;
        exit(0);
    }

    if (cin.peek() == 'c' || cin.peek() == 'C') {
        Utilities::clearInputStream();
        handleUserInput(); // Restart input process
        return;
    }

    // Store the validated inputs in member variables
    Calculator::setInitialDeposit(initialInvestment);
    Calculator::setMonthlyDeposit(monthlyDeposit);
    Calculator::setRate(annualInterestRate);
    Calculator::setTermLength(numberOfYears);
    
    Utilities::clearInputStream();
}

void UserInterface::getCompoundInterestandBalance(){
    Calculator::getCompoundInterestandBalance();
    cout << Utilities::alternatingCharString('*', ' ', 50) << endl;
    cout << "Press 'enter' to continue to annual chart, " << endl;
    cout<< " 'c' to make changes, or 'q' to quit." << endl;    
    
    if (cin.peek() == 'q' || cin.peek() == 'Q') {
        cout << Utilities::repeatingCharString('=', 50) << endl;
        cout << Utilities::centerString("Thank you for using Airgead Banking!", 50) << endl;
        cout << Utilities::alternatingCharString('*', ' ', 50) << endl;
        exit(0);
    }
    if (cin.peek() == 'c' || cin.peek() == 'C') {
        Utilities::clearInputStream();
        handleUserInput(); // Restart input process
        return;
    }   
    cin.get(); // Wait for user to press Enter  
    displayInvestmentGrowthChart(); // Proceed to growth chart
    Utilities::clearInputStream();
}

void UserInterface::displayInvestmentGrowthChart(){
    Utilities::clearScreen();
    Calculator::getGrowthChartNumbers();
  
    cout << "Press 'q' to exit or 'enter' to start over." << endl;
    if (cin.peek() == 'q' || cin.peek() == 'Q') {
        cout << Utilities::repeatingCharString('=', 50) << endl;
        cout << Utilities::centerString("Thank you for using Airgead Banking!", 50) << endl;
        cout << Utilities::alternatingCharString('*', ' ', 50) << endl;
        exit(0);
    }     
    run(); // Restart
}