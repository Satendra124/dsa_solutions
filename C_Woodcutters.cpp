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
    vector<pair<int,int>> trees;
    for (int i = 0; i < n; i++)
    {
        int x,h;
        cin>>x>>h;
        trees.push_back({x,h});
    }
    trees.push_back({INT_MAX,0});
    int ans = 0;
    //1st tree fell to its left
    ans++;
    int lastCord =trees[0].first;
    for (int i = 1; i < n; i++)
    {
        if(trees[i].first-lastCord>trees[i].second){
            //fell to left
            //cout<<"left "<<trees[i].first-lastCord<<endl;
            ans++;
            lastCord = trees[i].first;
        }else if(trees[i+1].first - trees[i].first>trees[i].second){
            //fell to right
           // cout<<"right"<<endl;
            ans++;
            lastCord = trees[i].first + trees[i].second;
        }else{
            //tree donot fell
            lastCord = trees[i].first;
            //cout<<"SKIP"<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}