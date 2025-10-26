#ifndef PROJECT2_CALCULATOR_H
#define PROJECT2_CALCULATOR_H   

class Calculator {
public:
    static void setInitialDeposit(double t_principal);
    static void setMonthlyDeposit(double t_monthlyDeposit);
    static void setRate(double t_Rate);
    static void setTermLength(int t_termLength);
    static void getInitialDeposit();
    static void getMonthlyDeposit();
    static void getRate();
    static void getTermLength();
    static void getCompoundInterestandBalance();
    static void getGrowthChartNumbers();
private:
    static double initialDeposit;    
    static double monthlyDeposit;
    static double annualInterestRate;
    static int termLength;
    static double yearEndBalance;
    static double yearEndInterest;
};

#endif