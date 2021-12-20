#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
string s[N];
int n, m, q, d[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            d[j] += (s[i - 1][j] == 'X' && s[i][j - 1] == 'X');
    for (int i = 1; i < m; i++)
        d[i] += d[i - 1];
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (d[l - 1] == d[r - 1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}