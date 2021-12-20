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
        if(n%4!=0) {
            cout<<"NO"<<endl;
            continue;
        }else{
            vector<vector<int>> a(2);
            cout<<"YES"<<endl;
            int p1=1,p2=n;
            bool c = false;
            while(p1<p2){
                c = !c;
                a[c].push_back(p1++);
                a[c].push_back(p2--);
            }
            sort(a[0].begin(),a[0].end());
            sort(a[1].begin(),a[1].end());
            for (int i = 0; i < a[0].size(); i++)
            {
                cout<<a[0][i]<<" ";
            }
            cout<<endl;
            for (int i = 0; i < a[1].size(); i++)
            {#include <bits/stdc++.h>
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
        if(n%4!=0) {
            cout<<"NO"<<endl;
            continue;
        }else{
            vector<vector<int>> a(2);
            cout<<"YES"<<endl;
            int p1=1,p2=n;
            bool c = false;
            while(p1<p2){
                c = !c;
                a[c].push_back(p1++);
                a[c].push_back(p2--);
            }
            sort(a[0].begin(),a[0].end());
            sort(a[1].begin(),a[1].end());
            for (int i = 0; i < a[0].size(); i++)
            {
                cout<<a[0][i]<<" ";
            }
            cout<<endl;
            for (int i = 0; i < a[1].size(); i++)
            {
                cout<<a[1][i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
                cout<<a[1][i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}