#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    vector<pair<int,int>> dates;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        dates.push_back({a,b});
    }
    sort(dates.begin(),dates.end());
    int day = 0;
    for (int i = 0; i < n; i++)
    {
        if(dates[i].second>=day){
            day = min(dates[i].second,dates[i].first);
        }else{
            day = dates[i].first;
        }
    }
    cout<<day<<endl;
    return 0;
}