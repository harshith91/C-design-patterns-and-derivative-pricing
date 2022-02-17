#ifndef SIMPLE_MC
#define SIMPLE_MC
#include "PayOff1.h"

double SimpleMonteCarlo2(const PayOff& PayOff, 
                        double Expiry,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths);

#endif