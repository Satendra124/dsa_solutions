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
    int T = t;
    while (t--)
    {
        ll n, d, c, m;
        cin >> n >> d >> c >> m;
        string s;
        cin >> s;
        bool ans = true;
        bool sw = false;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == 'D')
            {
                s = s.substr(0, i + 1);
                sw = true;
                break;
            }
        }
        if (!sw)
            s = "";
        for (char si : s)
        {
            if (si == 'C')
            {
                c--;
                if (c < 0)
                {
                    ans = false;
                    break;
                }
            }
            else
            {
                d--;
                if (d < 0)
                {
                    ans = false;
                    break;
                }
                c += m;
            }
        }
        if (ans)
            cout << "Case #" << T - t << ": YES" << endl;
        else
            cout << "Case #" << T - t << ": NO" << endl;
    }
    return 0;
}