#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int computeXOR(int n)
{
   
  if (n % 4 == 0)
    return n;
 
  if (n % 4 == 1)
    return 1;
 
  if (n % 4 == 2)
    return n + 1;
 
  return 0;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        int ans = 0;
        ans += a;
        int xor_val = computeXOR(a-1);
        if(xor_val!=b) {
            int req = xor_val ^ b;
            if(req==a) ans+=2;
            else ans++;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}