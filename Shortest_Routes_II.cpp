#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
const ll inf = 1e15;
int main()
{
    fast;
    int n,m,q;
    cin>>n>>m>>q;
    ll graph[n+1][n+1]={0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = inf;
        }
    }
    for (int i = 0; i < m; i++)
    {
        ll a,b,len;
        cin>>a>>b>>len;
        graph[a][b] = min(graph[a][b],len);
        graph[b][a] = min(graph[b][a],len);
    }
    ll distance[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            distance[i][j] = graph[i][j];
            if(i==j) distance[i][j] = 0;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if((distance[i][k]!=inf)&&(distance[k][j]!=inf))  distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }
    while (q--)
    {
        int u,v;
        cin>>u>>v;
        if(distance[u][v]==inf) cout<<-1<<endl;
        else cout<<distance[u][v]<<endl;
    }
    return 0;
}

//g++  5.4.0
 
// #include<bits/stdc++.h>
// using namespace std;
 
// #define ff first
// #define ss second
// #define int long long
// #define pb push_back
// #define pii pair< int,int >
// #define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
// const int nax = 5e2+5;
// const int inf = 1e15;
// int dp[nax][nax];
 
// void Floyd_Warshall(int n)
// {
//     for(int i=1 ; i<=n ;i++ ) dp[i][i] = 0;
 
//     for(int i=1 ; i<=n ;i++ )
//         for(int j=1; j<=n ; j++ )
//             for(int k=1; k<=n ; k++ )
//                 dp[j][k] = min( dp[j][k] , dp[j][i] + dp[i][k] );
//     return ;
 
// }
 
// signed main()
// {
//     fast ;
//     int n , m , q;
//     cin >> n >> m >> q;
 
//     for(int i=1 ; i<=n ;i++ )
//         for(int j=1; j<=n ; j++ )
//             dp[i][j] = inf;
//     for(int i=0 ; i<m ; i++ )
//     {
//         int u , v, w;
//         cin >> u >> v >> w;
//         dp[u][v] = min(dp[u][v],w);
//         dp[v][u] = min(dp[v][u],w);
 
//     }
//     Floyd_Warshall(n);
//     for(int i = 1 ; i<= q ; i++ )
//     {
//         int u ,v;
//         cin >> u >> v;
//         if( dp[u][v] != inf ) cout << dp[u][v] << "\n";
//         else                  cout << "-1\n";
//     }
// }