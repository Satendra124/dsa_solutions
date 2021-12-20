#include <bits/stdc++.h>
using namespace std;
int main()
{
    double N = 3;
    double D = 5;
    double sum = 0;
    while (N<=41)
    {
        //cout<<N<<"/"<<D<<"^2"<<endl;
        sum += N/(D*D);
        N += 2;
        D += 3;
    }
    cout<<sum<<endl;
    return 0;
}