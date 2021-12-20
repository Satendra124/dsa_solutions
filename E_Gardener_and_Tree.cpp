#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, vector<int>> graph;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool visited[n + 1];
        memset(visited, false, sizeof(visited));
        queue<vector<int>> q;
        for (int i = 1; i <= n; i++)
        {
            if (graph[i].size() <= 1)
                q.push({i, k});
        }
        int ans = n;
        while (!q.empty())
        {
            int cur = q.front()[0];
            int k_cur = q.front()[1];
            q.pop();
            if (k_cur == 0)
                continue;
            //if (visited[cur])
            //    continue;
            //visited[cur] = true;
            ans--;
            for (int &nxt : graph[cur])
            {
                q.push({nxt, k_cur - 1});
            }
        }
        cout << ans << endl;
    }
    return 0;
}