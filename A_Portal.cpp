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
        int n, m;
        cin >> n >> m;
        string in[n];
        for (int i = 0; i < n; i++)
        {
            cin >> in[i];
        }

        int grid[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = in[i][j] - '0';
            }
        }
        int pre[n + 1][m + 1];
        memset(pre, 0, sizeof(pre));
        int pre1[n + 1][m + 1];
        memset(pre1, 0, sizeof(pre));
        int pre2[n + 1][m + 1];
        memset(pre2, 0, sizeof(pre));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                pre1[i + 1][j + 1] = pre1[i + 1][j] + grid[i][j];
                pre[i + 1][j + 1] = pre[i + 1][j] + grid[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pre2[i + 1][j + 1] = pre2[i][j + 1] + grid[i][j];
                pre[i + 1][j + 1] += pre[i][j + 1];
            }
        }
        int ans = INT_MAX;
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int i2 = i1 + 4; i2 < n; i2++)
            {
                for (int j1 = 0; j1 < m; j1++)
                {
                    for (int j2 = 3 + j1; j2 < m; j2++)
                    {
                        // REM: pre1 --------->
                        // pre2 down
                        // pre dia
                        /*
                            --------i1--------         
                            |        |       |
                            |        |       |
                            j1---------------j2
                            |        |       |
                            |        |       |
                            ---------i2-------
                        */
                        //in the i1 row how much 1 are there from j1 to j2?
                        int i1Onces = pre1[i1 + 1][j2] - pre1[i1 + 1][j1 + 1];
                        int i2Onces = pre1[i2 + 1][j2] - pre1[i2 + 1][j1 + 1];
                        int j1Onces = pre2[i2][j1 + 1] - pre2[i1 + 1][j1 + 1];
                        int j2Onces = pre2[i2][j2 + 1] - pre2[i1 + 1][j2 + 1];
                        int insideOnces = pre[i2][j2] - pre[i1 + 1][j2] + pre[i1 + 1][j1 + 1] - pre[i2][j1 + 1];
                        int cost = insideOnces + (j2 - j1 - 1 - i1Onces) + (j2 - j1 - 1 - i2Onces) + (i2 - i1 - 1 - j1Onces) + (i2 - i1 - 1 - j2Onces);
                        //cout << cost << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
                        ans = min(ans, cost);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}