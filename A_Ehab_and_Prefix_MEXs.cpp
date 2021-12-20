#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

int justBigger(vector<int> &visited, int start, int end)
{
    int ans = -1;
}

int main()
{
    fast;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> portion;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            portion[arr[i]] = arr[i + 1];
        }
    }
    portion[arr[n - 1]] = 1e5;
    vector<int> visited;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int num = justBigger(visited, arr[i] + 1, portion[arr[i]]);
        if (num == -1)
            int num2 = justSmaller(visited, arr[i] + 1, portion[arr[i]]);
        b.push_back(arr[i] - 1);
        else
        {
            b.push_back(num);
            visited.push_back(num);
        }
    }

    return 0;
}