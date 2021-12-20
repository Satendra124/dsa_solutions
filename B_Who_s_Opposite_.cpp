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
        ll a,b,c;
        cin>>a>>b>>c;
        if(a>b) swap(a,b);
        // a<b 
        ll in_middle = (b-a) - 1;
        ll max_no = 2*(b-a);
        ll gap = b-a;
        if(in_middle != (a - 1 + max_no - b) || (a>max_no) || (b>max_no)|| c>max_no) cout<<-1<<endl;
        else if(c-gap>0 && c-gap<=max_no) cout<<c-gap<<endl;
        else if(c+gap<=max_no) cout<<c+gap<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}