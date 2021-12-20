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
    //n^2
    int arr[n*n];
    int p1 = 1;
    int p2 = n*n;
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n/2;j++){
            cout<<p1++<<" "<<p2--<<" ";
        }
        cout<<endl;
    }
}