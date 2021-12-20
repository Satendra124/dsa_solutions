#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

vector<int> primeFactors(int n)
{
    vector<int> fcs;
    if(n%2==0) fcs.push_back(2);
    while (n % 2 == 0)
    {
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if(n%i==0) fcs.push_back(i);
        while (n % i == 0)
        {
            n = n/i;
        }
    }
    if (n > 2)
        fcs.push_back(n);
    return fcs;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        vector<int> fcs = primeFactors(a);
        bool ans = true;
        for (int i = 0; i < fcs.size(); i++)
        {
            if(b%fcs[i]!=0){
                ans = false;
                break;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}