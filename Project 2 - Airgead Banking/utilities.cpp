#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

#include "utilities.h"

using namespace std;
// naming conventions: t_ for parameters, m_ for member variables - function descriptions are in the function names in utilities.h

bool Utilities::isValidPositiveDouble(const string& t_string) {
    istringstream iss(t_string);
    double value;
    char extra;
    if (!(iss >> value) || (iss >> extra)) {
        return false; // Not a valid double
    }
    return value > 0; // Check if positive
}

bool Utilities::isValidPositiveInt(const string& t_string) {
    istringstream iss(t_string);
    int value;
    char extra;
    if (!(iss >> value) || (iss >> extra)) {
        return false; // Not a valid integer
    }
    return value > 0; // Check if positive
}

double Utilities::stringToDouble(const string& t_string) {
    return stod(t_string);
}       

int Utilities::stringToInt(const string& t_string) {
    return stoi(t_string);
}

void Utilities::clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string Utilities::repeatingCharString(char t_char, int t_count) {
    return string(t_count, t_char);
}

string Utilities::alternatingCharString(char t_char1, char t_char2, int count
) {
    string result;
    for (int i = 0; i < count; ++i) {
        result += (i % 2 == 0) ? t_char1 : t_char2;
    }
    return result;
}

string Utilities::centerString(const string& str, int width) {
    if (width <= str.length()) {
        return str; // No centering needed
    }
    int totalPadding = width - str.length();
    int paddingLeft = totalPadding / 2;
    int paddingRight = totalPadding - paddingLeft;
    return string(paddingLeft, ' ') + str + string(paddingRight, ' ');
}

string Utilities::formatCurrency(double amount) {
    ostringstream oss;
    oss << fixed << setprecision(2) << "$" << amount;           
    return oss.str();
}

string Utilities::formatPercentage(double rate) {
    ostringstream oss;
    oss << fixed << setprecision(2) << rate * 100 << "%";
    return oss.str();
}

void Utilities::clearScreen() {
    // Clear the console screen
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// End of utilities.cpp: Implementation of utility functions