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
        int n, w;
        cin >> n >> w;
        map<int, int> recs;
        int M = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            recs[temp]++;
            M = max(M, temp);
        }
        int cur = 0;
        int h = 0;
        int left = 0;
        while (n > 0)
        {

            if (cur == 0)
            {

                cur = M;
                if (left < cur)
                {
                    left = w;
                    h++;
                }
            }
            if (left < cur)
            {
                cur /= 2;
                continue;
            }
            if (!recs[cur])
            {
                cur /= 2;
                continue;
            }

            n--;
            recs[cur]--;
            left -= cur;
        }
        cout << h << endl;
    }
    return 0;
}