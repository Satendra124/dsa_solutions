#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int dp[101][1001];
int prices[101];
int minPrice = -1;
void getMinCost(int k,int i,int price){

    if(k==0) {
        if(minPrice==-1 || minPrice>price) minPrice = price;
    }
    if(i==0) return;
    if(prices[i]!=-1 && prices[i]<=k){
        getMinCost(k-i-1,i,price+prices[i]);
        getMinCost(k,i-1,price);
    }else{
        getMinCost(k,i-1,price);
    }
}


int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {

        int n,k;
        cin>>n>>k;
        for (int i = 0; i < k; i++)
        {
            cin>>prices[i];
        }
        getMinCost(k,k-1,0);
        cout<<minPrice<<endl;
    }
    return 0;
}