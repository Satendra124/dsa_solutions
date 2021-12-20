#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
map<int,vector<int>> graph;
int back[100001];

vector<int> ans;
void backtrack(int s){
    int l = s;
    ans.push_back(s);
    s = back[s];
    while(s!=l){
        ans.push_back(s);
        s = back[s];
    }
    ans.push_back(s);
}

int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    bool visited[n+1];
    bool ansG = false;
    for (int i = 1; (i <= n)&&!ansG; i++)
    {
        bool visitedT[n+1];
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(visitedT[cur]) {
                backtrack(cur);
                ansG = true;
                break;  
            }else if(visited[cur]) continue;
            visited[cur]  = true;
            visitedT[cur]  = true;
            for(int e:graph[cur]){
                back[e] = cur;
                q.push(e);
            }
        }   
    }
    if(ans.size()>1){
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
    }else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}