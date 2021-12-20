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
        ll arr[n+2];
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        arr[n+1] = 0;
        ll score = 0;
        //calculate current score
        for (int i = 0; i <= n; i++)
        {
            score += abs(arr[i+1] - arr[i]);
        }
        
        //cout<<score<<endl;
        //need to find isolates
        ll profit = 0;
        for (int i = 1; i <= n; i++)
        {
            profit += max(0ll,arr[i]-max(arr[i-1],arr[i+1]));
        }
        cout<<score-profit<<endl;
        
    }
    return 0;
}