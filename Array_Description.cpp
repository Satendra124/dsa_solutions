#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int arr[100001];
int n,m;
int numOArr(int in){
    if(in==0) return 1;
    if(arr[in-1]!=0) return numOArr(in-1);
    else{
        
    }
}

int main()
{
    fast;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    
    
    return 0;
}