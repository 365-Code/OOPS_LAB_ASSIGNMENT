#include <iostream>
using namespace std;

int main() {
    double pounds, kilograms;
    // Prints the name of current file
    cout << __FILE__ << endl;

    // Conversion from Pounds to Kilogram
    cout << "Enter the weight in pounds: ";
    cin >> pounds;
    kilograms = pounds * (0.45359);
    cout << pounds << " pounds = " << kilograms << " kilograms." << endl;

    // Conversion from Kilogram to Pounds
    cout << "Enter the weight in kilograms: ";
    cin >> kilograms;
    pounds = kilograms * (2.20462);
    cout << kilograms << " kilograms = " << pounds << " pounds." << endl;

    return 0;
}