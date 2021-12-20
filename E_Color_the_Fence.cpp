#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;
bool sortfn(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    else if (a[0] > b[0])
        return false;
    else
        return a[1] > b[1];
}

int main()
{
    fast;
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 1; i <= 9; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back({temp, i});
    }
    sort(arr.begin(), arr.end(), sortfn);
    int digits = n / arr[0][0];
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << arr[i][0] << " " << arr[i][1] << endl;
    // }

    if (digits == 0)
        cout << -1 << endl;
    else
        cout << string(digits, '0' + arr[0][1]) << endl;

    return 0;
}