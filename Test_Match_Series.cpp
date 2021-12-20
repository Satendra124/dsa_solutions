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
        int res[2];
        res[0] = 0;
        res[1] = 0;
        for (int i = 0; i < 5; i++)
        {
            int r;
            cin >> r;

            if (r == 1)
                res[0]++;
            else if (r == 2)
                res[1]++;
        }
        if (res[0] > res[1])
            cout << "INDIA" << endl;
        else if (res[1] > res[0])
            cout << "ENGLAND" << endl;
        else
            cout << "DRAW" << endl;
    }
    return 0;
}