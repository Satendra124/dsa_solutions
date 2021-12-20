#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;
bool p(ll n){
    return (n!=0 && ((n)&(n-1))==0);
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll i =2;
        if(n==2){
            cout<<"Bob"<<endl;
        }else if(n==1){
            cout<<"Alice"<<endl;
        }else if(n%2==0){
            if(p(n+2)) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }else{
            if(p(n+1)) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
    }
    return 0;
}