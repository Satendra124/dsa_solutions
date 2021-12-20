#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n,m;
    cin>>n;
    cin>>m;
    string s;
    cin>>s;
    // 6 cases possible
    // abc
    // acb
    // bac
    // bca
    // cab
    // cba
    string poss_strings[6] = {"abc","acb","bac","bca","cab","cba"};
    int cost[n+1][6];
    for (int j = 0; j < 6; j++)
    {
        int cst =0;
        cost[0][j] = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]!=poss_strings[j][i%3]) {
                cst++;
            }
            cost[i+1][j] = cst;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int l,r;
        cin>>l>>r;
        int m = INT_MAX;
        for (int j = 0; j < 6; j++)
        {
            m = min(m,cost[r][j] - cost[l-1][j]);   
        }
        cout<<m<<endl;
    }
    

    return 0;
}