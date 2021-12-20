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
        int o=0,e=0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]%2) o++;
            else e++;
        }
        int ods_av = (n+1)/2;
        int evs = n - ods_av;
        cout<<min(ods_av,e) + min(evs,o)<<endl;
        
    }
    return 0;
}