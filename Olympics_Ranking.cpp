#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

// int ranks(){
//     int g1,s1,b1,g2,s2,b2;
//     cin>>g1>>s1>>b1>>g2>>s2>>b2;
//     if(g1>g2) return 1;
//     else if(g1<g2) return 2;
//     else{
//         if(s1>s2) return 1;
//         else if(s1<s2) return 2;
//         else{
//             if(b1>b2) return 1;
//             else return 2;
//         }
//     }
//     return 1;
// }

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int g1,s1,b1,g2,s2,b2;
        cin>>g1>>s1>>b1>>g2>>s2>>b2;
        cout<<1 + ((g1+s1+b1)<(g2+s2+b2))<<endl;
    }
    return 0;
}