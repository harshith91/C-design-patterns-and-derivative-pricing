#ifndef PAYOFF2
#define PAYOFF2

class PayOff
{
    public:
        PayOff(){};
        virtual double operator()(double Spot) const=0;
        virtual ~PayOff(){};
    private:
};

class PayOffCall : public PayOff
{
    public:
        PayOffCall(){double Strike_};
        double operator()(double Spot) const;
        ~PayOffCall(){};
    private:
        double Strike;    
};

class PayOffPut : public PayOff
{
    public:
        PayOffPut(){double Strike_};
        double operator()(double Spot) const;
        ~PayOffPut(){};
    private:
        double Strike;
};

#endif

