#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    cout<<4*n+12<<endl;
    //5 lines
    //1st line
    for (int i = 1; i <= 2*n; i++){
        cout<<2*i<<" "<<0<<endl;
    }
    //2nd line
    for (int i = 0; i <= 2*n+2; i++){
        cout<<i<<" "<<1<<endl;
    }
    //3rd line
    cout<<0<<" "<<2<<endl;
    for (int i = 1; i <= 2*n; i++){
        cout<<2*i<<" "<<2<<endl;
    }
    cout<<2*n+2<<" "<<2<<endl;
    //4th line
    cout<<0<<" "<<3<<endl;
    cout<<2*n+2<<" "<<3<<endl;
    //5th line
    for (int i = 0; i <= 2*n+2; i++){
        cout<<i<<" "<<4<<endl;
    }
}