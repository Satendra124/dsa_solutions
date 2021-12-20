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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        vector<int> v;
        v.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if(v[0]>=arr[i]) v.insert(v.begin(),arr[i]);
            else v.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}