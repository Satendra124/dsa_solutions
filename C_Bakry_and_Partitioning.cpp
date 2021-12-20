#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;
int cut = 0;
int whyAreYouReadingMyCode(map<int, vector<int>> &tree, ll val[], ll tot_xor, int cur, int last)
{
    int ans = val[cur];
    for (int next : tree[cur])
    {
        if (next != last)
        {
            ans ^= whyAreYouReadingMyCode(tree, val, tot_xor, next, cur);
        }
    }
    if (ans == tot_xor && cur != 1)
    {
        cut++;
        ans = 0;
    }
    return ans;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        cut = false;
        map<int, vector<int>> tree;
        int n, k;
        cin >> n >> k;
        ll val[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> val[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        ll tot_xor = 0;
        for (int i = 1; i <= n; i++)
        {
            tot_xor ^= val[i];
        }
        if (tot_xor == 0 && k > 1)
        {
            cout << "YES" << endl;
        }
        else if (k < 3)
        {
            cout << "NO" << endl;
        }
        else
        {
            int ans = whyAreYouReadingMyCode(tree, val, tot_xor, 1, -1);
            if ((ans == tot_xor && cut > 0) || (ans == 0 && cut > 1))
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}