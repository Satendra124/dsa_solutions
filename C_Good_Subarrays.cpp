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
        int n; cin>>n; 
        vector<int> v(n); 
        char c;
        for(int i = 0; i<n; i++){
            cin>>c; v[i] = c-'0';
        }
    
        unordered_map<int,int> m;
        m[0] = 1;
        ll count = 0;
        int s = 0;
        int x;
        for(int i = 0; i<n; i++){
            s += v[i];
            x = s-i-1;
            if(m.find(x)== m.end()){
                m[x] = 0;
            }
            m[x] += 1;
            count += m[x] -1;
        }
        cout<<count<<'\n';
    }
    return 0;
}