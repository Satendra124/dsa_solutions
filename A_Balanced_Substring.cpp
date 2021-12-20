#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

vector<int> solve(string s){
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int a =0,b=0;
            for (int k = i; k <= j; k++)
            {
                if(s[k]=='a') a++;
                else b++;
            }
            if(a==b) return {i+1,j+1};
            
        }
        
    }
    
    return {-1,-1};
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> ans = solve(s);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}