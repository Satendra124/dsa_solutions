#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

class vertex{
    public:
    int height;
    int nChild;
    int num;
    vertex(){
        num = 0;
        height = 0;
        nChild = 0;
    }
};

int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    vector<int> tree[n+1];
    vector<vertex> vs(n+1);
    for (int i = 1; i <= n; i++) vs[i].num = i;
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int maxH = 0;
    queue<pair<int,int>> q;
    q.push({1,0});
    vs[1].height = 0;
    while(!q.empty()){
        int cur = q.front().first;
        int last = q.front().second;
        q.pop();
        maxH = max(maxH,vs[cur].height);
        for(int e:tree[cur]){
            if(last!=e){
                vs[e].height = vs[cur].height+1;
                q.push({e,cur});
            }
        }
    }
    //we need number of childrens
    for(vertex node:vs)
        if(node.height==maxH) q.push({node.num,-1});

    vector<bool> visited(n,false);
    while(!q.empty()){
        int cur = q.front().first;
        int last = q.front().second;
        q.pop();
        for(int e:tree[cur]){
            if(last!=e){
                vs[e].nChild++;
                if(!visited[e]){
                    q.push({e,cur});
                    visited[e] = true;
                }
            }
        }
    }
    sort(vs.begin(),vs.end());
    vector<bool> isIndustrial(n);
    return 0;
}