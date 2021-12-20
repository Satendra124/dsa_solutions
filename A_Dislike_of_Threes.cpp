#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    vector<int> ar;
    for(int i=1;i<=5000;i++){
        if(i%3!=0 && i%10 != 3) ar.push_back(i);
    }
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<ar[n-1]<<endl;
    }
    return 0;
}