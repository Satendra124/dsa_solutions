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
        vector<int> time(n + 1, -1);
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            time[x] = 0;
        }
        map<int, vector<int>> graph;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            if (time[i] == 0)
            {
                q.push({i, 0});
            }
        }

        while (!q.empty())
        {
            int cur = q.front()[0];
            int ti = q.front()[1];
            q.pop();

            time[cur] = ti;
            for (int next : graph[cur])
            {
                if (time[next] == -1)
                    q.push({next, ti + 1});
            }
        }
        // for (int i = 1; i < n + 1; i++)
        // {
        //     cout << i << ": ";
        //     for (int j : graph[i])
        //         cout << j << " ";
        //     cout << "Time: " << time[i] << endl;
        //     cout << endl;
        // }

        bool ans = false;
        q.push({1, 0});
        while (!q.empty())
        {
            int cur = q.front()[0];
            int ti = q.front()[1];
            //cout << cur << " " << ti << " " << time[cur] << endl;
            q.pop();
            if (time[cur] <= ti)
                continue;
            if (graph[cur].size() == 1 && cur != 1)
            {
                ans = true;
                break;
            }
            for (int next : graph[cur])
            {
                q.push({next, ti + 1});
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}