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
        int n,q;
        cin>>n>>q;
        int pos_charge[n+1];
        int neg_charge[n+1];
        pos_charge[0] = 0;
        neg_charge[0] = 0;
        string s;
        cin>>s;
        for(int i=1;i<n+1;i++){
            if((s[i]=='+' && i%2==0) || (s[i]=='-' && i%2!=0)) {
                pos_charge[i] = pos_charge[i-1] + 1;
                neg_charge[i] = neg_charge[i-1];
            }
            else {
                neg_charge[i] = neg_charge[i-1] + 1;
                pos_charge[i] = pos_charge[i-1];
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            
        }
        
        


    }

    return 0;
}