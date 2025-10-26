#ifndef PROJECT2_UTILITIES_H
#define PROJECT2_UTILITIES_H

#include <string>

using namespace std;

class Utilities {
public:
    static bool isValidPositiveDouble(const string& t_string);
    static bool isValidPositiveInt(const string& t_string);
    static double stringToDouble(const string& t_string);
    static int stringToInt(const string& t_string);
    static void clearInputStream();
    static string repeatingCharString(char t_char, int t_count);
    static string alternatingCharString(char t_char1, char t_char2, int count);
    static string centerString(const string& str, int width);
    static string formatCurrency(double amount);
    static string formatPercentage(double rate);  
    static void clearScreen();
};



#endif // PROJECT2_UTILITIES_H: Utility functions for the Airgead Banking project

