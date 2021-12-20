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
    int k = t;
    while (t--)
    {
        int arr[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i!=1 || j!=1)
                cin>>arr[i][j];
            }
        }
        arr[1][1] = -1;
        vector<int> demands;
        //8 possibilities
        int ans = 0;
        if(arr[0][1]*2  == arr[0][2] + arr[0][0]) ans++;
        if(arr[2][1]*2 == arr[2][2] + arr[2][0]) ans++;
        if(arr[1][0]*2 == arr[2][0] + arr[0][0]) ans++;
        if(arr[1][2]*2 == arr[2][2] + arr[0][2]) ans++;
        if((arr[2][0] + arr[0][2])%2==0)
            demands.push_back((arr[2][0] + arr[0][2])/2);
        if((arr[0][0] + arr[2][2])%2==0)
            demands.push_back((arr[0][0] + arr[2][2])/2);
        if((arr[1][0] + arr[1][2])%2==0)
            demands.push_back((arr[1][0] + arr[1][2])/2);
        if((arr[0][1] + arr[2][1])%2==0)
            demands.push_back((arr[0][1] + arr[2][1])/2);

        sort(demands.begin(),demands.end());
        
        int cnt = 1;
        int max_cnt = 1;
        for(int i=1;i<demands.size();i++){
            if(demands[i-1]==demands[i]){
                cnt++;
            }else cnt = 1;
            max_cnt = max(cnt,max_cnt);
        }
        if(demands.size()==0) max_cnt = 0;
        cout<<"Case #"<<k - t<<": "<<ans + max_cnt<<endl;
        



    }
    return 0;
}