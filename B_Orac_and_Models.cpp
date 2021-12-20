#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
    
        vector<int> vec(n);
        for(int i = 0; i < n; ++i)
            cin >> vec[i];
    
        vector<int> dp(n + 1, 1);
    
        for(int i = 2; i <= n; ++i) 
            for(int j = 1; j * j <= i; ++j) 
                if(i % j == 0)  {
                    if(vec[i - 1] > vec[j - 1])
                        dp[i] = max(dp[i], dp[j] + 1);
                    if(vec[i - 1] > vec[i / j - 1])
                        dp[i] = max(dp[i], dp[i / j] + 1);
                }
        /*
        for(int i = 1; i <= n; ++i)
            cout << dp[i] << " ";
        cout << "\n";
        */
    
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
}
