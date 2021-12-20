#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
bool sortFn(vector<ll> &a,vector<ll>&b){
    return a[a.size()-2] < b[b.size()-2];
}


int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<ll>> caves(n);
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            for (int j = 0; j < k; j++)
            {
                int temp;
                cin>>temp;
                caves[i].push_back(temp);
            }
        }
        for(int i=0;i<n;i++){
            vector<ll> v = caves[i];
            ll r = 0;
            ll cur = 0;
            for(ll p:v){
                if(p<cur){
                    cur++;
                }else{
                    r += p + 1 - cur;
                    cur = p+2;
                }
            }
            caves[i].push_back(r);
            caves[i].push_back(cur);
        }
        sort(caves.begin(),caves.end(),sortFn);
        ll ans = 0;
        ll req = 0;
        for(int i=0;i<n;i++){
            if(ans < caves[i][caves[i].size()-2]){
                ans =  caves[i][caves[i].size()-2];
                req = caves[i][caves[i].size()-2];
            }
            ans += caves[i][caves[i].size()-1] - caves[i][caves[i].size()-2];
        }
        cout<<req<<endl;
    }
    return 0;
}