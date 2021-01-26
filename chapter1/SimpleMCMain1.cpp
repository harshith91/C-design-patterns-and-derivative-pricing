#include "Random1.h"
#include <iostream>
#include <cmath>

using namespace std;


double GetOneGaussianByBoxMuller()
{
    double result;

    double x;
    double y;

    double sizeSquared;
    do
    {
        x = 2.0*rand()/static_cast<double>(RAND_MAX) - 1;
        y = 2.0*rand()/static_cast<double>(RAND_MAX) - 1;
        sizeSquared = x*x + y*y;
    }
    while (sizeSquared >= 1.0);
    
    result = x*sqrt(-2*log(sizeSquared)/sizeSquared);

    return result;
}



double SimpleMonteCarlo1(double Expiry, double Strike, double Spot, double Vol, double r,
unsigned long NumberOfPaths)
{
    double variance_t = Vol*Vol*Expiry;
    double sigma_t = sqrt(variance_t);
    double itoCorrection = -0.5*variance_t;

    double nSpot = Spot*exp(r + itoCorrection);
    double Spot_t;
    double runningSum = 0;
    // Sampling from the number of paths
    for(unsigned long i=0; i<NumberOfPaths; i++)
    {
        double w = GetOneGaussianByBoxMuller();
        // double w = GetOneGaussianBySummation();

        Spot_t = nSpot*exp(sigma_t);
        double payoff = Spot_t - Strike;
        payoff = (payoff > 0) ? payoff : 0;
        runningSum += payoff;
    }

    double mean = runningSum/NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

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

    double result = SimpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, NumberOfPaths);

    cout <<"The Price is: "<<result << "\n";

    double tmp;
    cin >> tmp;

    return 0;
}