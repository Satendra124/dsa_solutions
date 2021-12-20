#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

void assign(map<int,int>& evns,int cur,int pos){
    if(cur==0) return;
    if(evns[cur]){
        return;
    }
    evns[cur] = pos;
    assign(evns,cur-2,pos);
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
        int odd[n];
        int even[n];
        for (int i = 0; i < n; i++)
        {
            cin>>odd[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>even[i];
        }
        map<int,int> evns;
        for (int i = 0; i < n; i++)
        {
            assign(evns,even[i],i);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int req = odd[i] +1 ;
            int pos = evns[req];
            //cout<<req<<" "<<pos<<endl;
            ans = min(ans,i+pos);
        }
        cout<<ans<<endl;

        
    }
    return 0;
}