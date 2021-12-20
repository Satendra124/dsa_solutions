#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int solve(vector<int>& arr){
    int n = arr.size();
    int mis[3][3];
    memset(mis,0,sizeof(mis));
    for (int i = 0; i < n; i++)
    {
        if(i%3!=arr[i]%3){
            mis[i%3][arr[i]%3]++;
        }
    }
    int ans = 0;
    for(int i=0;i<3;i++){
        for (int j = i+1; j < 3; j++)
        {
            int temp = min(mis[i][j],mis[j][i]);
            mis[i][j] -= temp;
            mis[j][i] -= temp;
            ans += temp;
        }
    }
    int a2 = 0;
    for(int i=0;i<3;i++){
        for (int j = 0; j < 3; j++)
        {
            a2 += mis[i][j];
        }
    }
    if(a2>0) a2--;
    return ans+a2;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr)<<endl;

    }
    return 0;
}