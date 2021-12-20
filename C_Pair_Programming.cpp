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
        int k,n,m;
        cin>>k>>n>>m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin>>b[i];
        }
        bool possible = true;
        int ans[n+m];
        int i=0,j=0;
        while(i<n||j<m){
            if(i<n && a[i]==0){
                ans[i+j] = 0;
                k++;
                i++;
            }else if(j<m && b[j]==0){
                ans[i+j] = 0;
                k++;
                j++;
            }else if(i<n && k>=a[i]){
                ans[i+j] = a[i];
                i++;
            }else if(j<m && k>=b[j]){
                ans[i+j] = b[j];
                j++;
            }else{
                //cout<<i<<" - "<<j<<endl;
                possible = false;
                break;
            }
        }
        if(possible){
            for (int i = 0; i < n+m; i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            
        }else cout<<"-1"<<endl;
    }
    return 0;
}