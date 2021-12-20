#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n;
    cin>>n;
    ll nos[n];
    for (int i = 0; i < n; i++)
    {
        cin>>nos[i];
    }
    int ans[n];
    ans[0] = -1;
    stack< pair<int,ll> > s;
    s.push(pair<int,ll>(0,nos[0]));
    for (int i = 0; i < n; i++)
    {
        while(!s.empty()&& s.top().second<=nos[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top().first+1;
        }
        s.push(pair<int,ll>(i,nos[i]));
    }
    stack< pair<int,ll> > s1;
    for (int i = n-1; i >= 0; i--)
    {
        while(!s1.empty()&& s1.top().second<=nos[i]){
            s1.pop();
        }
        if(s1.empty()){
            ans[i] += -1;
        }else{
            ans[i] += s1.top().first+1;
        }
        s1.push(pair<int,ll>(i,nos[i]));
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}