#ifndef PAYOFF
#define PAYOFF

class PayOff
{
    public:
        enum OptionType{call, put};
        PayOff(double strike_, OptionType option_type_);
        double operator()(double Spot) const;

    private:
        double strike;
        OptionType option_type;

};

#endif