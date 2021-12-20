#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

long long opt(int n,int p,int k){
    int c = p%k;
    long long ans = 0;
    //n--;
    if(n%k > c){
        ans += (n/k + 1)*c;
    }else{
        ans += (n/k + 1)*(n%k) + (n/k)*(c-n%k);
    }
    ans += p/k;
    return ans+1;
}

// int brute(int n,int p,int k){
//     int c = p%k;
//     int ans = 0;
//     for(int i=0;i<c;i++){
//         for (int j = 0; j < n; j++)
//         {
//             if(j%k==i) ans++;
//         }
//     }
//     for (int j = 0; j < n; j++)
//     {
//         if(j%k==c) ans++;
//         if(j==p) return ans;
//     }
//     return 0;
// }

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n,p,k;
        cin>>n>>p>>k;
        // for (int i = 1; i < n; i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         for (int l = 1; l < k; l++)
        //         {
        //             int ao = opt(i,j,l);
        //             int br = brute(i,j,l);
        //             if(br!=ao) cout<<ao<<" "<<br<<" NO "<<i<<" "<<j<<" "<<l<<endl; 
        //         }
                
        //     }
            
        // }
        cout<<opt(n,p,k)<<endl;
        
    }
    return 0;
}