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
        string s;
        cin>>s;
        map<pair<int,int>,int> history;
        pair<int,int> ans = {-1,n};
        pair<int,int> cur = {0,0};
        history[cur] = 0;
        for (int i = 0; i < n; ++i)
        {
            if(s[i]=='R')cur.first++;
            else if(s[i]=='L') cur.first--;
            else if(s[i]=='U') cur.second++;
            else if(s[i]=='D') cur.second--;
            if(history.count(cur)){
                if(ans.second - ans.first > i - history[cur]){
                    ans.first = history[cur];
                    ans.second = i;
                }
            }
            history[cur] = i+1;
        }
        if(ans.first!=-1)
        cout<<ans.first+1<<" "<<ans.second+1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}