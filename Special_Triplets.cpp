#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
const int maxs = 1e5;
vector<int> v[maxs + 1];

int main()
{
    fast;
    int t;
    cin>>t;
    for(int i = 1; i <= maxs; i++){
        for(int j = 2*i; j <= maxs; j += i){
            v[j].push_back(i);
        }
    }
    while (t--)
    {
        int n;
        cin>>n;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for(int div:v[i]){
                ans += int((n-div+i)/i);
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}