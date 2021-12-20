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
        int n,m,i,j;
        cin>>n>>m>>i>>j;
        int n1 = n/2;
        int m1 = m/2;
        if(i<=n1 && j<=m1){
            //first quard
            cout<<n<<" "<<m<<" "<<1<<" "<<1<<endl;
        }else if(i<=n1 && j>m1){
            //3rd - return 2nd
            cout<<1<<" "<<m<<" "<<n<<" "<<1<<endl;
        }else if(i>n1 && j<=m1){
            //2nd quard - 3rd quard
            cout<<1<<" "<<m<<" "<<n<<" "<<1<<endl;
        }else {
            cout<<n<<" "<<m<<" "<<1<<" "<<1<<endl;
        }
    }
    return 0;
}