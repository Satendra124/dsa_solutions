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
        if(n<4) cout<<-1<<endl;
        else{
            int s;
            vector<int> ans;
            if(n%2) s = n;
            else s =  n-1;
            while(s!=3){
                ans.push_back(s);
                s-=2;
            }
            ans.push_back(3);
            ans.push_back(1);
            ans.push_back(4);
            ans.push_back(2);
            if(n>5){
                s = 6;
                while(s<=n){
                    ans.push_back(s);
                    s+=2;
                }
            }
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}