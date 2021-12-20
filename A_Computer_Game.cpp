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
        int n;
        cin >> n;
        string grid[2];
        cin >> grid[0];
        cin >> grid[1];
        queue<vector<int>> q;
        q.push({0, 0});
        bool visited[2][n];
        memset(visited, false, sizeof(visited));
        bool ans = false;
        while (!q.empty())
        {
            vector<int> point = q.front();
            q.pop();
            if (point[0] > 1 || point[0] < 0 || point[1] < 0 || point[1] > n - 1)
                continue;
            if (grid[point[0]][point[1]] == '1')
                continue;
            if (visited[point[0]][point[1]])
                continue;

            visited[point[0]][point[1]] = true;
            if (point[0] == 1 && point[1] == n - 1)
            {
                ans = true;
                break;
            }
            q.push({point[0] - 1, point[1]});
            q.push({point[0] - 1, point[1] + 1});
            q.push({point[0] - 1, point[1] - 1});
            q.push({point[0] + 1, point[1]});
            q.push({point[0] + 1, point[1] + 1});
            q.push({point[0] + 1, point[1] - 1});
            q.push({point[0], point[1]});
            q.push({point[0], point[1] + 1});
            q.push({point[0], point[1] - 1});
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}