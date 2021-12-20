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
        int n,initial;
        cin>>n>>initial;
        int low = initial,high = initial;
        string ans = "YES";
        int lastT = 0;
        while(n--){
            //check if is possible
            int t,l,h;
            cin>>t>>l>>h;
            int minCanGet = low - t + lastT;
            int maxCanGet = high + t - lastT;
            if(!(minCanGet<=h && maxCanGet>=l)){
                ans = "NO";
            }
            low = max(l,minCanGet);
            high = min(h,maxCanGet);
            lastT = t;
        }
        cout<<ans<<endl;
    }
    return 0;
}