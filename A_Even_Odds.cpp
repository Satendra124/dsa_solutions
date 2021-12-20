#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    int p  =0;
    for (ll i = 1; i <= n; i++)
    {
        if(i%2!=0){
            arr[p] = i;
            p++;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if(i%2==0){
            arr[p] = i;
            p++;
        }
    }
  
    cout<<arr[k-1]<<endl;
}