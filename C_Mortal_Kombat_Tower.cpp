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
        for (int i = 0; i < n; i++) cin>>arr[i];
        //first friend goes
        int zeros[n];
        zeros[n-1] = !arr[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            if(arr[i]==0) zeros[i] = 1 + zeros[i+1];
            else zeros[i] = 0;
            //cout<<zeros[i]<<" ";
        }
        int cost=0,i=0;
        bool turn = true; //true is friend false is he
        while (i<n)
        {
            //cout<<i<<endl;
            if(turn){
                //friend
                cost += arr[i];
                i++;
                if(!arr[i]){
                    if(zeros[i]!=2) i++;
                }
            }else{
                //he
                i++;
                if(arr[i]) i++;
                else {
                    if(zeros[i]!=1) i++; 
                }
            }
            turn = !turn;
        }
        cout<<cost<<endl;
    }
    return 0;
}