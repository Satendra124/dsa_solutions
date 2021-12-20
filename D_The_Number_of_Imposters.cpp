#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;
bool contra = false;

void imposters(int cur, vector<vector<vector<int>>> &rel, vector<bool> &visited, vector<bool> &truths, bool truth, int &ans)
{
    if (visited[cur])
    {
        if (truths[cur] == truth)
            return;
        else
        {
            contra = true;
            return;
        }
    }
    visited[cur] = true;
    truths[cur] = truth;
    if (truth)
    {
        for (int i : rel[cur][0])
        {
            imposters(i, rel, visited, truths, false, ans);
        }

        for (int i : rel[cur][1])
        {
            imposters(i, rel, visited, truths, true, ans);
        }
        for (int i : rel[cur][2])
        {
            imposters(i, rel, visited, truths, false, ans);
        }

        for (int i : rel[cur][3])
        {
            imposters(i, rel, visited, truths, true, ans);
        }
    }
    else
    {
        ans++;
        for (int i : rel[cur][1])
        {
            imposters(i, rel, visited, truths, false, ans);
        }

        for (int i : rel[cur][0])
        {
            imposters(i, rel, visited, truths, true, ans);
        }
        for (int i : rel[cur][3])
        {
            imposters(i, rel, visited, truths, false, ans);
        }

        for (int i : rel[cur][2])
        {
            imposters(i, rel, visited, truths, true, ans);
        }
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<vector<int>>> rel(n + 1, vector<vector<int>>(4));
        // rel[person][0] --> who he thinks is imposter | rel[person][1] -->who he thinks is crewmate
        // rel[person][2] --> who thinks he is imposter | rel[person][3] -->who thinks he is crewmate

        for (int i = 0; i < m; i++)
        {
            int u, v;
            string r;
            cin >> u >> v >> r;
            if (r == "imposter")
            {
                rel[u][0].push_back(v);
                rel[v][2].push_back(u);
            }
            else
            {
                rel[u][1].push_back(v);
                rel[v][3].push_back(u);
            }
        }
        vector<bool> visited(n + 1);
        bool isContradict = false;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            contra = false;
            vector<bool> truths(n + 1, true);
            vector<bool> v1 = visited;
            vector<bool> v2 = visited;
            int im1 = 0;

            imposters(i, rel, v1, truths, true, im1);
            truths = vector<bool>(n + 1, true);
            bool c1 = contra;
            contra = false;
            int im2 = 0;
            imposters(i, rel, v2, truths, false, im2);
            if (!c1 && !contra)
            {
                if (im1 > im2)
                {
                    ans += im1;
                    visited = v1;
                }
                else
                {
                    ans += im2;
                    visited = v2;
                }
            }
            else if (!c1)
            {
                ans += im1;
                visited = v1;
            }
            else if (!contra)
            {
                ans += im2;
                visited = v2;
            }
            else
            {
                isContradict = true;
                break;
            }
        }
        if (isContradict)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}