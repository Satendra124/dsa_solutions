#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        char cord[n][n];
        int f[2]={-1,-1},s[2]={-1,-1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>cord[i][j];
                if(cord[i][j]=='*'){
                    if(f[0]==-1){
                        f[0] = i;
                        f[1] = j;
                    }else{
                        s[0] = i;
                        s[1] = j;
                    }
                }
            }
            
        }
        if(s[0]==f[0]){
            if(s[0]>0){
                cord[s[0]-1][f[1]] = '*';
                cord[f[0]-1][s[1]] = '*';
            }else{
                cord[s[0]+1][f[1]] = '*';
                cord[f[0]+1][s[1]] = '*';
            }
        }else if(f[1]==s[1]){
            if(s[1]>0){
                cord[s[0]][f[1]-1] = '*';
                cord[f[0]][s[1]-1] = '*';
            }else{
                cord[s[0]][f[1]+1] = '*';
                cord[f[0]][s[1]+1] = '*';
            }
        }else{
            cord[s[0]][f[1]] = '*';
            cord[f[0]][s[1]] = '*';
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<cord[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}