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
        string r1,r2;
        cin>>r1>>r2;
        int ans = 0;
        int lastTaken = -1;
        for (int i = 0; i < n; i++)
        {
            if((r1[i]=='0' && r2[i]=='1') || (r1[i]=='1' && r2[i] == '0') ){
                ans += 2;
            }else if(r1[i]=='0' && r2[i]=='0'){
                if(lastTaken!=i-1 && i>0 && r1[i-1]=='1' && r2[i-1]=='1'){
                    ans += 2;
                    lastTaken = i-1;
                }else if(i<n-1 && r1[i+1]=='1' && r2[i+1]=='1'){
                    ans += 2;
                    lastTaken = i+1;
                }else ans +=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}