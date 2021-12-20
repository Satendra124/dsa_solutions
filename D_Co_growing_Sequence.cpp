#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int x[n];
        int y[n];
        for (int i = 0; i < n; i++)
        {
            cin>>x[i];
        }
        y[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int a = x[i-1] ^ y[i-1];
            //a & (x[i]^...) = a
            int b ;
            if(a%2==0){
                b = a-1;
            }else{
                b = a+1;
            }
            y[i] = b ^ x[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout<<y[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}