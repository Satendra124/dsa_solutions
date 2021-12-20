#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
#include <iostream>

using namespace std;

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool foundzero = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                foundzero = true;
                if (i >= n/2) {
                    cout << 1 << " " << i + 1 <<" "<< 1 << " " << i << endl;
                    break;
                } else {
                    cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
                    break;
                }
            }
        }
        if (!foundzero) {
            cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
        }
    }
}