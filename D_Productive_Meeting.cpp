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
        priority_queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            q.push({temp,i+1});
        }
        vector<vector<int>> ans;
        while(q.size()>=2){
            vector<int> cur = q.top();
            q.pop();
            vector<int> nxt = q.top();
            q.pop();
            if(nxt[0]==0) break;
            ans.push_back({cur[1],nxt[1]});
            cur[0]--;
            nxt[0]--;
            q.push(cur);
            q.push(nxt);
        }
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        }
        
    }
    return 0;
}