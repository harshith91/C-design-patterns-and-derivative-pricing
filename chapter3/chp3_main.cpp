#include <iostream>
#include "PayOff2.h"

using namespace std;


int main()
{
    double Expiry;
    double Spot;
    double Strike;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter Expiry\n";
    cin >> Expiry;

    cout << "\nEnter Strike\n";
    cin >> Strike;

    cout << "\nEnter Spot\n";
    cin >> Spot;

    cout << "\nEnter Vol\n";
    cin >> Vol;

    cout << "\nr\n";
    cin >> r;

    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayOffCall call_payoff(Strike);
    PayOffPut put_payoff(Strike);


    double call_price = SimpleMonteCarlo2(call_payoff, Expiry, Spot, Vol, r, NumberOfPaths);
    double put_price = SimpleMonteCarlo2(put_payoff, Expiry, Spot, Vol, r, NumberOfPaths);

    cout <<"The Call Price is: "<< call_price << "\n";
    cout <<"The Put Price is: "<< put_price << "\n";

    return 0;
}