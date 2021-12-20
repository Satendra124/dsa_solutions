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
        int a[n];
        vector<int> goes;
        vector<int> comes;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if(a[i]==0) goes.push_back(i);
            if(a[i]==1 ) comes.push_back(i);
        }
        int g=0,c=0;
        while(g<goes.size() && c<comes.size()){
            if(goes[g]+1==comes[c]) break;
            if(goes[g]<goes[c]) g++;
            else c++;
        }
        if(g==goes.size() || c==comes.size()){
            if(a[0]==1){
                cout<<n+1<<" "<<1<<" ";
                for (int i = 1; i < n; i++)
                {
                    cout<<i+1<<" ";
                }
                
            }else cout<<-1<<endl;
        }else{
            for (int i = 0; i < n; i++)
            {
                if(i==comes[c]) continue;
                if(i==goes[g]) cout<<goes[g]+1<<" "<<n+1<<" "<<comes[c]+1<<" ";
                else cout<<i+1<<" ";
            }
        }
        cout<<endl;
        
    }
    return 0;
}