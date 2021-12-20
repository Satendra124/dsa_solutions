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
        ll n;
        cin>>n;
        ll pips = 0;
        //total floors
        ll f = n/4;
        pips += f*11*4;
        int left = n%4;
        if(left==0){
            if(f>0) pips += 16;
        }else if(left==1){
            pips += 20;
            if(f>0) pips += 12;
        }else if(left == 2){
            pips += 36;
            if(f>0) pips += 8;
        }else if(left==3){
            pips += 51;
            if(f>0) pips += 4;
        }
        cout<<pips<<endl;
    }
    return 0;
}