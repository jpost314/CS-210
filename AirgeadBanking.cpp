//Jordan Poston 
//4/05/2025
//Airgead Banking Interest Calculator

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Investment {
private:
    float initialInvestment, monthlyDeposit, annualInterestRate;
    int years;
public:
    Investment() {
        cout << "--------------------------------------\n";
        cout << "========== Airgead Banking ===========\n";
        cout << "----------   Data Input    -----------\n";
        cout << "Initial Investment Amount: $";
        cin >> initialInvestment;
        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;
        cout << "Annual Interest Rate (%): ";
        cin >> annualInterestRate;
        cout << "Number of years: ";
        cin >> years;
    }

    void displayWithoutDeposits() {
        //Calculate the number of months
        int months = years * 12;
        //Displays the year data without deposits
        cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
        cout << "=================================================================\n";
        cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
        cout << "-----------------------------------------------------------------\n";

        float yearEndBalance = initialInvestment;
        for (int i = 0; i < years; i++) {
            float yearEndInterest = yearEndBalance * (annualInterestRate / 100);
            yearEndBalance = yearEndBalance + yearEndInterest;
            cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << yearEndBalance
                << "\t\t\t$" << yearEndInterest << "\n";
        }
    }
    //Displays year data with monthly deposits
    void displayWithDeposits() {
        cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
        cout << "=================================================================\n";
        cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
        cout << "-----------------------------------------------------------------\n";

        float yearEndBalance = initialInvestment;
        for (int i = 0; i < years; i++) {
            float yearEndInterest = 0;
            for (int j = 0; j < 12; j++) {
                float monthlyInterest = (yearEndBalance + monthlyDeposit) * (annualInterestRate / 100 / 12);
                yearEndInterest = yearEndInterest + monthlyInterest;
                yearEndBalance = yearEndBalance + monthlyDeposit + monthlyInterest;
            }
            cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << yearEndBalance
                << "\t\t\t$" << yearEndInterest << "\n";
        }
    }
};

int main() {
    Investment invest;
    invest.displayWithoutDeposits();
    invest.displayWithDeposits();
    return 0;
}