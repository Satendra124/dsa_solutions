#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int prod(int start,int end){
    ll result = 1;
    for (int i = start; i <= end; i++)
        result = (result * i) % mod;
 
    return result%mod;
}

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
        sort(arr,arr+n);
        int max = arr[n-1];
        int max_no = 0;
        int sec_max = -1;
        int sec_no = 1;
        for (int i = n-1; i>=0; i--)
        {
            if(arr[i]==max) max_no++;
            else if(sec_max<arr[i]) sec_max = arr[i];
            else if(sec_max==arr[i]) sec_no++;
            else break;
        }
        //cout<<max<<" "<<sec_max<<endl;
        if(sec_max==-1 || max-sec_max<=1){
            if(sec_max==-1){
                cout<<prod(1,n)<<endl;
            }else{
                if(max_no>1){
                    cout<<prod(1,n)<<endl;
                }else{
                    int rest = n - max_no - sec_no;
                    ll minus = 0;
                    for (int i = sec_no; i < n-1; i++)
                    {
                        if(i==sec_no) ans += prod(1,rest);
                        else ans += prod(i-sec_no+1,i)*prod(1,rest);
                    }

                    cout<<prod() - ans<<endl;
                }
            }
        }else cout<<0<<endl;
    }
    return 0;
}