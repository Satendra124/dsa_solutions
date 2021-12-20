// #include <bits/stdc++.h>
// using namespace std;
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long int
// int mod = 1e9+7;
// int n,m;

// int32_t main()
// {
//     fast;
//     cin>>n>>m;
//     vector<int> p(n, -1);
//     vector<tuple<int,int,int>> edges;
//     for (int i = 0; i < m; i++)
//     {
//         int u,v,w;
//         cin>>u>>v>>w;
//         edges.push_back({u,v,w});
//     }
//     vector<int> d(n+1,1e18);
//     d[1]=0;
//     int last ;
//     for (int i = 1; i <= n; i++)
//     {
//         last = -1;
//         for(auto x:edges){
//             int u,v,w;
//             tie(u,v,w) = x;
//             if(d[u]+w<d[v]){
//                 d[v] = d[u]+w;
//                 last = v;
//                 p[v] = u;
//             }
//         }
//     }
//     if(last==-1) cout<<"NO"<<endl;
//     else{
//         cout<<"YES"<<endl;
//         for (int i = 0; i < n; ++i)
//             last = p[last];
//         vector<int> c;
//         for (int v = last;; v = p[v]) {
//             c.push_back(v);
//             if (v == last && c.size() > 1)
//                 break;
//         }
//         reverse(c.begin(),c.end());
//         for (int i = 0; i < c.size(); i++)
//         {
//             cout<<c[i]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
 
using namespace std;
 
typedef long long ll;
typedef tuple<ll, ll, ll> e;
typedef vector<e> ve;
typedef vector<ll> vi;
 
const ll INF = 100000000000000000LL;
 
int main() {
  int n, m;
  cin >> n >> m;
  ve e(m);
  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    e[i] = {a-1, b-1, c};
  }
  vi d(n), p(n);
  for (int i = 0; i < n; i++) d[i] = INF;
  int x;
  for (int i = 0; i < n; i++) {
    x = -1;
    for (auto z:e) {
      ll a, b, c;
      tie(a, b, c) = z;
      if (d[a] + c < d[b]) {
        d[b] = d[a] + c;
        p[b] = a;
        x = b;
      }
    }
  }
  if (x == -1) cout << "NO\n";
  else {
    for (int i = 0; i < n; i++) x = p[x];
    int o = x;
    vi a(1, o);
    do {
      x = p[x];
      a.push_back(x);
    } while (x != o);
    reverse(a.begin(), a.end());
    cout << "YES\n";
    for (int i = 0; i < a.size(); i++) {
      cout << a[i] + 1;
      if (i < a.size() - 1) cout << " ";
    }
    cout << endl;
  }
}