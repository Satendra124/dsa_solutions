#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

bool canForm(int sc[][5], int n, int d1, int d2)
{
    int onD1 = 0;
    int onD2 = 0;
    int onBoth = 0;
    for (int i = 0; i < n; i++)
    {
        if (sc[i][d1] == 1 && sc[i][d2] == 1)
            onBoth++;
        else if (sc[i][d1] == 1)
            onD1++;
        else if (sc[i][d2] == 1)
            onD2++;
    }
    int x2 = onD2 + onBoth - onD1;
    if (x2 < 0 || x2 % 2 != 0)
        return false;
    int x = x2 / 2;
    int y = onBoth - x;
    //    cout << onD1 << " " << onD2 << " " << x << " " << y << endl;
    if (x >= 0 && y >= 0 && onD1 + x == onD2 + y && onD2 + y == n / 2)
        return true;
    else
        return false;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sc[n][5];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> sc[i][j];
            }
        }
        bool ans = false;
        for (int d1 = 0; d1 < 5; d1++)
        {
            for (int d2 = d1 + 1; d2 < 5; d2++)
            {
                ans = ans || canForm(sc, n, d1, d2);
                //cout << d1 << " " << d2 << " " << ans << endl;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}