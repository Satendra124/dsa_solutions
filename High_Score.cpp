#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int n,m;
map<ll,vector<pair<ll,ll>>> graph; // 1 - {index,point}
bool visited[2501];
bool isCycle[2501];
ll cycleScore[2501];
bool isPath[2501];
//vector<int> cycle(2501,-1);
ll ans = LONG_LONG_MIN;
bool isInfinite = false;

void checkifCycle(vector<ll> path){
    for(ll a:path){
        if(isCycle[a]){
            isInfinite = true;
            return;
        }
        isPath[a] = true;
    }
}

void dfs(ll cur,ll score,vector<ll> path){
    if(cur==n){
        ans = max(ans,score);
        path.push_back(cur);
        checkifCycle(path);
        for(pair<ll,ll> a:graph[cur]){
            dfs(a.first,score+a.second,path);
        }
        return;
    }
    if(visited[cur]){
        if(score>cycleScore[cur]) {
            isCycle[cur] = true;
            if(isPath[cur]) {
                isInfinite = true;
                return;
            }
        }
        return;
    }
    visited[cur] = true;
    cycleScore[cur] = score;
    path.push_back(cur);
    for(pair<ll,ll> a:graph[cur]){
        dfs(a.first,score+a.second,path);
    }
}

int main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    dfs(1ll,0ll,{});
    if(isInfinite) cout<<-1<<endl;
    else 
    cout<<ans<<endl;
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// template<typename... T>
// void see(T&... args) { ((cin >> args), ...);}
// template<typename... T>
// void put(T&&... args) { ((cout << args << " "), ...);}
// template<typename... T>
// void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
// #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
// #define int long long
// #define pb push_back
// #define F first
// #define S second
// #define ll long long
// #define ull unsigned long long
// #define ld long double
// #define pii pair<int,int>
// #define vi vector<int>
// #define vii vector<pii>
// #define vc vector
// #define L cout<<'\n';
// #define E cerr<<'\n';
// #define all(x) x.begin(),x.end()
// #define rep(i,a,b) for (int i=a; i<b; ++i)
// #define rev(i,a,b) for (int i=a; i>b; --i)
// #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define setpr(x) cout<<setprecision(x)<<fixed
// #define sz size()
// #define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
// #define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
// #define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
// const ll inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);
// const ll md = 1000000007;

// int dis[2505];
// const int M =1e16;
// vi adj[2505], adj2[2505];
// bool vis[2505], vis2[2505];
// void dfs(int s){
//     if (vis[s]) return;
//     vis[s]=1;
//     for (auto i: adj[s]) dfs(i);
// }
// void dfs2(int s){
//     if (vis2[s]) return;
//     vis2[s]=1;
//     for (auto i: adj2[s]) dfs2(i);
// }
// void solve(){
//     int n,m; see(n,m);
//     rep(i,1,n+1) dis[i]=M;
//     dis[1]=0;
//     vc<tuple<int,int,int>> e;
//     rep(i,0,m){
//         int a,b,w; see(a,b,w);
//         e.pb({a,b,-w});
//         adj[a].pb(b), adj2[b].pb(a);
//     }
//     dfs(1), dfs2(n);
//     rep(i,0,n){
//         for ( auto [a,b,w]: e){
//             if (dis[b]> dis[a]+w){
//                 dis[b] = dis[a]+w;
//                 if (i==n-1 && vis[b] && vis2[b]) {put(-1); return;}
//             }
//         }
//     }
//     put(-dis[n]);
    
// }    
// signed main(){
//     IOS;
//     #ifdef LOCAL
//     freopen("input.txt", "r" , stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     int t=1;
//     //cin>>t;
//     while(t--){
//         solve();
//         //cout<<'\n';
//     }
//     #ifdef LOCAL
//     clock_t tStart = clock();
//     cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
//     #endif
// }