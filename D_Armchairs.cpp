#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int points[5000]; // records points for each one
int arr[5000];
int n;
bool saraksarak(int i){

}

void sarak(int i){
    for (int j = 0; j < n; j++)
    {
        
        
    }
    
}

int main()
{
    fast;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        points[i] = 0;
    }
    ll cost = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1) sarak(i);
    }
    for (int i = 0; i < n; i++)
    {
        cost += points[i];
    }
    cout<<cost<<endl;
    return 0;
}




int ans = INT_MAX;
        if(arr[i]==0||arr[i]==-1) continue;
        //left
        int index = -1;
        int lspare = -1;
        for (int l = i-1; l >=0; l--)
        {
            if(arr[l]==0) {
                if(ans>abs(l-i)){
                    ans = abs(l-i);
                    index = l;
                    break;
                }
            }else if(arr[l]==-1){
                lspare = l;
            }
        }
        //right
        for (int l = i+1; l < n; l++)
        {
            if(arr[l]==0) {
                if(ans>abs(l-i)){
                    ans = abs(l-i);
                    index = l;
                    break;
                }
                
            }
        }
        cost += ans;
        arr[index] = -1;