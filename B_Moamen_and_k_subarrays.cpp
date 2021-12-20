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
        int n,k;
        cin>>n>>k;
        int arr[n];
        int srtarr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            srtarr[i] = arr[i];
        }
        sort(srtarr,srtarr+n);
        map<int,int> last;
        last[srtarr[0]] = -2e9;
        for(int i=1;i<n;i++) last[srtarr[i]] = srtarr[i-1];
        int ans = 0; 
        for (int i = 1; i < n; i++)
        {
            if(last[arr[i]] != arr[i-1] ) ans++;
        }
        if(ans+1<=k) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}