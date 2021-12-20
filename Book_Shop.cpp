// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9+7;
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// typedef long long int ll;
// int main()
// {
//     fast;
//     int n,p;
//     cin>>n>>p;
//     int price[n+1],pages[n+1];
//     for (int i = 1; i < n+1; i++)
//     {
//         cin>>price[i];
//     }
//     for (int i = 1; i < n+1; i++)
//     {
//         cin>>pages[i];
//     }
    
//     int dp[n+1][p+1];
//     memset(dp,0,sizeof(dp));
//     for (int i = 1; i < n+1; i++)
//     {
//         for (int j = 1; j < p+1; j++)
//         {
//             if(price[i]<=j){
//                 dp[i][j] = max(pages[i] + dp[i-1][j-price[i]],dp[i-1][j]);
//             }else{
//                 dp[i][j] = dp[i-1][j];
//             }
//         }   
//     }
//     cout<<dp[p][n]<<endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,x;
    cin>>n>>x;

    vector<int> page(n),price(n);
    int a,b;

    for(int&i : price)
    cin>>i;

    for(int&i : page)
    cin>>i;

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            //option1 = book number i-1 is not included, hence no pages added.
            //option2 = book number i-1 is included, hence pages are added.
            //option1 = dp[i-1][j] ...book not included so total price(j) remains same.
            //option2 = dp[i-1][j-price[i-1]] + page[i-1]....total price(j) decreased and pages are counted for book i-1.
            
            dp[i][j] = dp[i-1][j];
            if(j >= price[i-1])
            {
                dp[i][j] = max (dp[i][j],dp[i-1][j-price[i-1]] + page[i-1]); //max of both the boxes included in dp[i][j]. 
            }
        }
    }

    cout<< dp[n][x] <<endl;

    return 0;
}