#include <iostream>

using namespace std;

class CurrencyConverter {
public:
    double convert(double amount, string fromCurrency, string toCurrency) {
        if (fromCurrency == "USD" && toCurrency == "INR") {
            // Conversion rate from USD to INR
            double conversionRate = 73.5;
            return amount * conversionRate;
        } else if (fromCurrency == "USD" && toCurrency == "EUR") {
            // Conversion rate from USD to EUR
            double conversionRate = 0.9;
            return amount * conversionRate;
        } else if (fromCurrency == "EUR" && toCurrency == "INR") {
            // Conversion rate from EUR to INR
            double conversionRate = 85.0;
            return amount * conversionRate;
        } else {
            cout << "Unsupported currency conversion: " << fromCurrency << " to " << toCurrency << endl;
            return 0.0;
        }
    }
};

int main() {
    CurrencyConverter converter;

    double amountUSD = 100.0;
    double convertedAmount;

    // Converting USD to INR
    convertedAmount = converter.convert(amountUSD, "USD", "INR");
    cout << amountUSD << " USD is equivalent to " << convertedAmount << " INR." << endl;

    // Converting USD to EUR
    convertedAmount = converter.convert(amountUSD, "USD", "EUR");
    cout << amountUSD << " USD is equivalent to " << convertedAmount << " EUR." << endl;

    // Converting EUR to INR
    double amountEUR = 50.0;
    convertedAmount = converter.convert(amountEUR, "EUR", "INR");
    cout << amountEUR << " EUR is equivalent to " << convertedAmount << " INR." << endl;

    return 0;
}
