#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

void primeFactors(int n, vector<int> &primes)
{
    while (n % 2 == 0)
    {
        primes.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primes.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        primes.push_back(n);
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> facts;
        primeFactors(n, facts);
        int odds = 0;
        int evens = 0;
        for (int i = 0; i < facts.size(); i++)
        {
            //cout << facts[i] << endl;
            if (facts[i] % 2)
                odds++;
            else
                evens++;
        }
        //cout << evens << " " << odds << endl;
        if (a <= 0 && b <= 0)
        {
            if (odds && evens)
                cout << max(a, b) << endl;
            else if (odds)
                cout << b << endl;
            else
                cout << a << endl;
        }
        else if (a <= 0)
        {
            if (odds)
            {
                cout << b * odds << endl;
            }
            else
            {
                cout << a << endl;
            }
        }
        else if (b <= 0)
        {
            if (evens)
            {
                cout << a * evens << endl;
            }
            else
            {
                cout << b << endl;
            }
        }
        else
        {
            cout << a * evens + b * odds << endl;
        }
    }
    return 0;
}