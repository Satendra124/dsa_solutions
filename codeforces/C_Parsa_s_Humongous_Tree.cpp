#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

vector<vector<ll>> dp(100005,vector<ll>(2,0));
map<int,vector<int>> tree;
int l[100005],r[100005];
void dfs(int cur,int last){
    dp[cur][0] = dp[cur][1] = 0;
    for(int v:tree[cur]){
        if(v!=last) {
            dfs(v,cur);
            dp[cur][0] += max(dp[v][0]+abs(l[cur]-l[v]),dp[v][1]+abs(l[cur]-r[v]));
            dp[cur][1] += max(dp[v][0]+abs(r[cur]-l[v]),dp[v][1]+abs(r[cur]-r[v]));
        }
    } 
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
        tree.clear();
        for (int i = 1; i <= n; i++)
        {
            cin>>l[i]>>r[i];
        }
        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        //dp
        dfs(1,-1);
        cout<<max(dp[1][0],dp[1][1])<<endl;
    }
    return 0;
}



















// ll getSum(vector<vector<int>>& edges,vector<vector<int>>& lv){
//     ll sum = 0;
//     vector<int> nums(edges.size()+2,-1);
//     for(vector<int> e:edges){
//         ll s = 0;
//         if(nums[e[0]]==-1){
//             if(nums[e[1]]==-1){
//                 int s1 = abs(lv[e[0]][0]-lv[e[1]][1]);
//                 int s2 = abs(lv[e[0]][1]-lv[e[1]][0]);
//                 if(s1>s2){
//                     nums[e[0]] = lv[e[0]][0];
//                     nums[e[1]] = lv[e[1]][1];
//                 }else{
//                     nums[e[0]] = lv[e[0]][1];
//                     nums[e[1]] = lv[e[1]][0];
//                 }
//                 s += max(s1,s2);
//             }else{
//                 int s1 = abs(lv[e[0]][0]-nums[e[1]]);
//                 int s2 = abs(lv[e[0]][1]-nums[e[1]]);
//                 if(s1>s2){
//                     nums[e[0]] = lv[e[0]][0];
//                 }else{
//                     nums[e[0]] = lv[e[0]][1];
//                 }
//                 s += max(s1,s2);
//             }
//         }else{
//             if(nums[e[1]]==-1){
//                 int s1 = abs(nums[e[0]]-lv[e[1]][1]);
//                 int s2 = abs(nums[e[0]]-lv[e[1]][0]);
//                 if(s1>s2){
//                     nums[e[1]] = lv[e[1]][1];
//                 }else{
//                     nums[e[1]] = lv[e[1]][0];
//                 }
//                 s += max(s1,s2);
//             }else{
//                 int s1 = abs(nums[e[0]]-nums[e[1]]);
//                 s += s1;
//             }
//         }
//         sum += s;
//     }
//     return sum;
// }

// ll bfs(map<int,vector<int>>& tree,vector<vector<int>>& lv){
//     ll s = 0;
//     queue<pair<int,ll>> q;
//     vector<bool> visited1(lv.size()+1,false);
//     vector<bool> visited2(lv.size()+1,false);
//     q.push({1,lv[1][0]});
//     while(!q.empty()){
//         int e = q.front().first;
//         ll v = q.front().second;
//         q.pop();
//         if(visited1[e]) continue;
//         visited1[e] = true;
//         for(int vs:tree[e]){
//             //need k - 0 or 1
//             if(!visited1[vs]){
//                 int k;
//                 if(abs(v - lv[vs][0])>abs(v - lv[vs][1])) k = 0;
//                 else k =1;
//                 s += abs(v - lv[vs][k]);
//                 q.push({vs,lv[vs][k]});
//             }
//         }
//     }
//     ll s2 = 0;
//     q.push({1,lv[1][1]});
//     while(!q.empty()){
//         int e = q.front().first;
//         ll v = q.front().second;
//         q.pop();
//         if(visited2[e]) continue;
//         visited2[e] = true;
//         for(int vs:tree[e]){
//             //need k - 0 or 1
//             if(!visited2[vs]){
//                 int k;
//                 if(abs(v - lv[vs][0])>abs(v - lv[vs][1])) k = 0;
//                 else k =1;
//                 s2 += abs(v - lv[vs][k]);
//                 q.push({vs,lv[vs][k]});
//             }
            
//         }
//     }
//     return max(s,s2);
// }