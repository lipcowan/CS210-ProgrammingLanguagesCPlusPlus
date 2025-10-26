#include "calculator.h"  
#include "utilities.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Initialize static member variables
double Calculator::initialDeposit = 0.0;
double Calculator::monthlyDeposit = 0.0;
double Calculator::annualInterestRate = 0.0;
int Calculator::termLength = 0;
double Calculator::yearEndBalance = 0.0;
double Calculator::yearEndInterest = 0.0;

void Calculator::setInitialDeposit(double amount) {
    if (amount < 0) {
        throw invalid_argument("Initial deposit cannot be negative.");
    }
    initialDeposit = amount;
}   

void Calculator::setMonthlyDeposit(double amount) {
    if (amount < 0) {
        throw invalid_argument("Monthly deposit cannot be negative.");
    }
    monthlyDeposit = amount;
}

void Calculator::setRate(double rate) {
    if (rate < 0) {
        throw invalid_argument("Interest rate cannot be negative.");
    }
    annualInterestRate = rate;
}

void Calculator::setTermLength(int length) {
    if (length <= 0) {
        throw invalid_argument("Term length must be a positive integer.");
    }
    termLength = length;
}


void Calculator::getInitialDeposit() {
    cout << "Initial Deposit: $" << fixed << setprecision(2) << initialDeposit << endl;
}

void Calculator::getMonthlyDeposit() {
    cout << "Monthly Deposit: $" << fixed << setprecision(2) << monthlyDeposit << endl;
}

void Calculator::getRate() {
    cout << "Annual Interest Rate: " << fixed << setprecision(2) << annualInterestRate << "%" << endl;
}

void Calculator::getTermLength() {
    cout << "Term Length: " << termLength << " years" << endl;
}

// using the formula A = P(1 + r/n)^(nt) for compound interest only works if no monthly deposits
// with montly contributions, we need to add both the future value of the initial principal 
// and the future value of the annuity (monthly deposits)
void Calculator::getCompoundInterestandBalance() {
    double principal = initialDeposit;
    int n = 12; // compounding frequency (monthly)
    int t = termLength; // term length in years
    int totalMonths = t * n;
    double monthlyrate = annualInterestRate / 100 / n; // monthly interest rate
    double fvPrincipal = principal * pow((1 + monthlyrate), totalMonths);
    double fvAnnuity = monthlyDeposit * ( (pow(1 + monthlyrate, totalMonths) - 1) / monthlyrate ) * (1 + monthlyrate);
    double totalBalance = fvPrincipal + fvAnnuity;
    double totalInterest = totalBalance - (initialDeposit + monthlyDeposit * totalMonths);
    cout << "Final Balance: " << Utilities::formatCurrency(totalBalance) << endl;  
    cout << "Total Interest Earned: " << Utilities::formatCurrency(totalInterest) << endl;
    cout << Utilities::repeatingCharString('=', 50) << endl;
    return;    
}   

void Calculator::getGrowthChartNumbers() {
    double balance = initialDeposit;
    double monthlyrate = annualInterestRate / 100 / 12; // monthly interest rate
    cout << Utilities::repeatingCharString('=', 50) << endl;    
    cout << Utilities::centerString("Balance and Interest Without Monthly Deposits", 50) << endl;
    cout << Utilities::repeatingCharString('=', 50) << endl;
    cout << setw(10) << "Year" 
         << setw(20) << "Balance" 
         << setw(20) << "Interest" << endl;
    cout << Utilities::repeatingCharString('-', 50) << endl;    
    balance = initialDeposit; // reset balance to initial deposit
    for (int year = 1; year <= termLength; ++year) {
        double interestEarnedThisYear = 0.0;
        for (int month = 1; month <= 12; ++month) {
            double interestForThisMonth = balance * monthlyrate;
            interestEarnedThisYear += interestForThisMonth;
            balance += interestForThisMonth; // add interest earned this month
        }
    cout << setw(10) << year 
            << setw(20) << Utilities::formatCurrency(balance) 
            << setw(20) << Utilities::formatCurrency(interestEarnedThisYear) << endl;  
    }
    cout << Utilities::repeatingCharString('=', 50) << endl;

    if (monthlyDeposit <= 0) {
        return; // No monthly deposits to show
    }
   
    cout << Utilities::alternatingCharString('*', ' ', 52) << endl;
    cout << Utilities::repeatingCharString('=', 50) << endl;
    cout << Utilities::centerString("Balance and Interest With Monthly Deposits", 50) << endl;
    cout << Utilities::repeatingCharString('=', 50) << endl;    
    cout << setw(10) << "Year" 
         << setw(20) << "Balance" 
         << setw(20) << "Interest" << endl;
    cout << Utilities::repeatingCharString('-', 50) << endl;    
    for (int year = 1; year <= termLength; ++year) {
        double interestEarnedThisYear = 0.0;
        for (int month = 1; month <= 12; ++month) {
            balance += monthlyDeposit; // add monthly deposit at the start of the month
            double interestForThisMonth = balance * monthlyrate;
            interestEarnedThisYear += interestForThisMonth;
            balance += interestForThisMonth; // add interest earned this month
        }
    cout << setw(10) << year 
            << setw(20) << Utilities::formatCurrency(balance) 
            << setw(20) << Utilities::formatCurrency(interestEarnedThisYear) << endl;
    }
    cout << Utilities::repeatingCharString('=', 50) << endl;
    cout << Utilities::alternatingCharString('*', ' ', 52) << endl;
    return;
}
