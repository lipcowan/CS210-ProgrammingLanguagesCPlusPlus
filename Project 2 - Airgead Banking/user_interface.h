#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

class UserInterface {
public:
    void run();
    void displayIntro();
    void handleUserInput();
    void getCompoundInterestandBalance();
    void displayInvestmentGrowthChart();
private:
    int width = 50; // Standard width for formatting
};

#endif // USER_INTERFACE_H