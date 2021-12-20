#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int maxNo(int n){
    int maxN = 0;
    while (n)
    {
        maxN = max(maxN,n%10);
        n = n/10;
    }
    return maxN;
}

int main()
{
    fast;
    int n;
    cin>>n;
    int steps = 0;
    while (n)
    {
        steps++;
        n -= maxNo(n);
    }
    cout<<steps;
    return 0;
}