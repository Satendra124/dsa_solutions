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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int m=INT_MAX,M = INT_MIN;
        int mi,Mi;
        for (int i = 0; i < n; i++)
        {
            if(m>arr[i]){
                m = arr[i];
                mi = i;
            }
            if(M<arr[i]){
                M = arr[i];
                Mi = i;
            }
        }
        //cout<<mi<<" "<<Mi<<endl;
        int l = max(Mi,mi)+1;
        int r = max(n-mi,n-Mi);
        int m1 = mi+1 + n - Mi;
        int m2 = Mi+1 + n - mi;
        cout<<min(l,min(r,min(m1,m2)))<<endl; 

        
    }
    return 0;
}