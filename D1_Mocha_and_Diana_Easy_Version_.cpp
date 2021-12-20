#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int fin(int u,vector<int> parent){
    while(parent[u]!=u) u = parent[u];
    return u;
}

void unite(int u,int v,vector<int>& parent,vector<int>& size){
    u = fin(u,parent);
    v = fin(v,parent);
    if(size[u]<size[v]) swap(u,v);
    parent[v] = u;
    size[u] += size[v];
}
int main()
{
    fast;
    int t=1;
   // cin>>t;
    while (t--)
    {
        int n,m1,m2;
        cin>>n>>m1>>m2;
        vector<int> parent1(n);
        vector<int> parent2(n);
        vector<int> size1(n);
        vector<int> size2(n);
        for (int i = 0; i < n; i++)
        {
            parent1[i] = i;
            parent2[i] = i;
            size1[i] = 1;
            size2[i] = 1;
        }
        for (int i = 0; i < m1; i++)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            unite(u,v,parent1,size1);
        }
        for (int i = 0; i < m2; i++)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            unite(u,v,parent2,size2);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int pari1 = fin(i,parent1);
                int parj1 = fin(j,parent1);
                int pari2 = fin(i,parent2);
                int parj2 = fin(j,parent2);
                if(pari1!= parj1 && pari2 != parj2){
                    ans.push_back({i+1,j+1});
                    unite(pari1,parj1,parent1,size1);
                    unite(pari2,parj2,parent2,size2);
                }
            }
        }
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        }
    }
    return 0;
}