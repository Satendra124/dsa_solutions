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
        ll k;
        cin>>k;
        ll iteration = sqrt(k-1);
        ll start = iteration*iteration + 1;
        if(start + iteration >=k){
            //lies in vertical
            cout<<k-start+1<<" "<<iteration+1<<endl;
        }else{
            //in horiontal
            int end = (iteration+1)*(iteration+1);
            cout<<iteration+1<<" "<<end - k +1<<endl;

        }
    }
    return 0;
}