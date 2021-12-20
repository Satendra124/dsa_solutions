//if this works then ... no way cant work

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int main()
{
    int n;
	cin>>n;
	vector<ll> cost(n+1);
	for(int i=1;i<=n;i++)cin>>cost[i];
	string s[n+1][2];
	for(int i=1;i<=n;i++){
		cin>>s[i][0];
		s[i][1]=s[i][0];
		reverse(s[i][1].begin(),s[i][1].end());
	}
	ll dp[100005][2];
	for(int i=1;i<=n;i++){
		if(i==1){
			dp[1][0]=0;
			dp[1][1]=cost[1];
			continue;
		}
		for(int j=0;j<2;j++){
			dp[i][j]=1e18;
			if(s[i][j]>=s[i-1][0])dp[i][j]=min(dp[i][j],dp[i-1][0]+j*cost[i]);
			if(s[i][j]>=s[i-1][1])dp[i][j]=min(dp[i][j],dp[i-1][1]+j*cost[i]);
		}
	}	
	ll ans=min(dp[n][0],dp[n][1]);
	cout<<((ans>=1e18)?-1:ans)<<endl;	

}








   // //6 edges for every two elements

    // map<int,vector<int>> graph;
    // // rev index = -index
    // for (int i = 1; i < n; i++)
    // {
    //     graph[i].push_back(-i);
    //     graph[i].push_back(i+1);
    //     graph[i].push_back(-i-1);
    //     graph[-i].push_back(i+1);
    //     graph[-i].push_back(-i-1);
    //     graph[i+1].push_back(-i-1);
    // }
    
    // //dijkstras algo
    // int dist[2*n+1];
    // for(int i=0;i<2*n+1;i++) dist[i] = 1e7;
    // dist[n+1] = 0;
    // priority_queue<pair<int,int>> q;
    // q.push({0,1});
    // vector<bool> visited(2*n+1,false);
    // while(!q.empty()){
    //     int cur = q.top().second;
    //     q.pop();
    //     if(visited[n+cur]) continue;
    //     visited[cur+n] = true;
    //     for(int u:graph[cur]){
    //         int w;
    //         if(u>0) w = 0;
    //         else w = prices[-u];
    //         if((dist[cur+n]+w<dist[u+n]) && ((u == -cur) ||is_possible(cur,u,strs,revStrs)) ){
    //             dist[u+n] = dist[cur+n] + w;
    //             q.push({-dist[u+n],u});
    //         }
    //     }
    // }
    // int ans =min(dist[2*n],dist[0]);
    // if(ans==1e7) cout<<-1<<endl; 
    // else cout<<ans;
 