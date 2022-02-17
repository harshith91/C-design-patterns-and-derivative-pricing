#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mult(int a, int b)
{
    int c;
    c = a*b;
    return c;
}

void A()
{
    cout<<"Hello"<<endl;
}
void B(void (*ptr)())
{
    ptr();
}
int main()
{
    // int c[3][2][2] = {{{2,5},{7,9}},
    // {{3,4},{6,1}},
    // {{0,8},{11,13}}};

    // cout<<c<<endl;
    // cout<<*c<<endl;
    // cout<<c[0]<<endl;
    // cout<<&c[0][0]<<endl;
    // cout<<*(c[0][0]+1)<<endl;

    ////////////
     
    // int n;
    // cout<<"Enter size of array"<<endl;
    // cin>>n;
    // cout<<"Size of array is "<<n<<endl;

    // int *p;
    // p = new int[n];
    // for(int i=0;i<n;i++)
    // {
    //     p[i] = i*5;
    // }
    // cout<<p[4]<<endl;
    // delete p;

    // int n;
    // cout<<"Enter a mulitplier"<<endl;
    // cin>>n;

    // int *q;
    // q = new int;
    // *q = n;
    // cout<<(*q)*5<<endl;
    /////

    // int a, b;
    // a = 5;
    // b = 66;
    // int (*func)(int, int);
    // func = &mult;
    // int c = (*func)(a, b);
    // cout<<"Product is "<<c<<endl;
    void (*ptr)();
    ptr = A;
    B(A);
    return 0;
}