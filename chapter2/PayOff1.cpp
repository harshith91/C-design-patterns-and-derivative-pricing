#include "PayOff1.h"
#include <iostream>

using namespace std;

PayOff::PayOff(double strike_, OptionType option_type_)
{
    strike = strike_;
    option_type = option_type_;
}

double PayOff::operator()(double spot) const
{
    switch(option_type)
    {
        case call:
            return max(spot - strike, 0.0);
        case put:
            return max(strike - spot, 0.0);
        default:
            throw("Undefined option type !");
    }
}