#include <iostream>
#include "Random1.h"
#include "PayOff1.h"
#include <cmath>

double SimpleMonteCarlo2(const PayOff& thePayOff, 
                        double Expiry,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths)
{

    double var_t = Vol*Vol*Expiry;
    double root_var_t = sqrt(var_t);
    double itoCorrection = -0.5*var_t;

    double

    S_t = Spot*exp(r*Expiry + itoCorrection);

    double payoff_runningSum = 0;
    double final_spot;

    for(unsigned long i=0;i<NumberOfPaths;i++)
    {
        double gaussian_val = GetOneGaussianByBoxMuller();
        final_spot = S_t*exp(root_var_t*gaussian_val);
        double this_payoff = thePayOff(final_spot);
        payoff_runningSum += this_payoff;
    }

    double average_payoff = payoff_runningSum/NumberOfPaths;
    double option_val = exp(-r*Expiry)*average_payoff;

    return option_val;
}