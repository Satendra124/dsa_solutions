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
        vector<int> arr(4);
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
        vector<int> re = arr;
        sort(re.begin(),re.end(),greater<int>());
        int maxN = re[0];
        int maxNm = re[1];
        //cout<<maxN<<maxNm<<endl;
        if((arr[0]==maxN && arr[1]==maxNm) || (arr[0]==maxNm && arr[1]==maxN) || (arr[2]==maxN && arr[3]==maxNm) || (arr[2]==maxNm && arr[3]==maxN) ){
            cout<<"NO"<<endl;
        }else cout<<"YES"<<endl;
    }
    return 0;
}