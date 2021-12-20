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
        int univ[n];
        for (int i = 0; i < n; i++) cin>>univ[i];
        vector<ll> students[n];
        ll sum =0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            students[univ[i]-1].push_back(temp);
            sum+= temp;
        }
        for (int i = 0; i < n; i++)
        {
            sort(students[i].begin(),students[i].end());
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < students[i].size(); j++)
            {
                students[i][j] += students[i][j-1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            ll ans = sum;
            for (int j = 0; j < n; j++)
            {
                int index = students[j].size()%(i+1);
                if(index!=0)
                ans -= students[j][index-1];
            }
            cout<<ans<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}