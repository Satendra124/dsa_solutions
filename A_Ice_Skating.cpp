#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    int v[1001][1001];
    memset(v,0,sizeof(v));
    int po[n][2];
    for (int i = 0; i < n; i++)
    {
        int p,q;
        cin>>p>>q;
        po[i][0] = p;
        po[i][1] = q;
    }
    for (int i = 0; i < n; i++)
    {
        if(!v[po[i][0]][po[i][1]]){
            for(int j=0;j<1001;j++){
                if()
            }
        }
    }
    
    cout<<min(x.size(),y.size()) - 1<<endl;
    
    
    return 0;
}