#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;
int dp[501][250001];

bool solve(int n, int sum)
{
    if (sum == 0)
        return dp[n][sum] = true;
    if (n == 0)
        return dp[n][sum] = false;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (n <= sum)
    {
        return dp[n][sum] = solve(n - 1, sum - n) || solve(n - 1, sum);
    }
    else
    {
        return dp[n][sum] = solve(n - 1, sum);
    }
}

vector<int> dfs(int n, int s, int k, vector<int> ans)
{
    if (k == 0)
        return ans;
    if (s == 0 || n == 0)
        return {};
    if (n <= s)
    {
        if (dp[n - 1][s - n] == 1)
        {
            // n liya ja skta h
            vector<int> ab = ans;
            ans.push_back(n);
            ans = dfs(n - 1, s - n, k - 1, ans);
            if (ans.size() == 0)
            {
                //skip
                return dfs(n - 1, s, k, ab);
            }
            else
                return ans;
        }
        else
        {
            //skip
            return dfs(n - 1, s, k, ans);
        }
    }
    else
    {
        return dfs(n - 1, s, k, ans);
    }
    return {};
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        memset(dp, -1, sizeof(dp));
        solve(n, s);
        int k = r - l + 1;

        vector<int> v;
        vector<int> c(0);
        v = dfs(n, s, k + 1, c);
        if (v.size() > 0)
        {
            for (int &i : v)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}