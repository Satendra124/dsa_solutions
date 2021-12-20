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
        string s;
        cin >> s;
        int minSteps = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            int rem = 0;
            bool possible = true;
            int l = 0, r = s.size() - 1;
            while (l < r)
            {
                if (s[l] != s[r])
                {
                    if (s[l] == 'a' + i)
                    {
                        l++;
                        rem++;
                    }
                    else if (s[r] == 'a' + i)
                    {
                        r--;
                        rem++;
                    }
                    else
                    {
                        possible = false;
                        break;
                    }
                }
                else
                {
                    l++;
                    r--;
                }
            }
            if (possible)
                minSteps = min(minSteps, rem);
        }
        if (minSteps == INT_MAX)
            cout << -1 << endl;
        else
            cout << minSteps << endl;
    }
    return 0;
}