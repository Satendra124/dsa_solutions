#include <bits/stdc++.h>
//#include <algorithm>
using namespace std;
typedef long long ll;


bool mySortFn(pair<int,int>& a,pair<int,int>& b){
    return a.first<a.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll test;
    cin >> test;

    vector<pair<string, ll>> v;

    for (ll i = 0; i < test; i++) {
        vector<pair<int,int>> v;
        sort(v.begin(),v.end(),mySortFn);
        
    }
}