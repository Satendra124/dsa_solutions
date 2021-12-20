// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void flip(vector<int>& A){
        for(int& a:A){
            a = !a;
        }
    }

    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        for (int i = 0; i < n; i++)
        {
            if(A[i][0] == 0){
                flip(A[i]);
            }
        }
        int sum =0 ;
        for (int i = 0; i < m; i++)
        {
            int once = 0;
            for (int j = 0; j < n; j++)
            {
                if(A[j][i]==1) once++;
            }
            once = max(once,n-once);
            //cout<<once<<endl;
            sum += pow(2,m-i-1)*once;
        }
        return sum;        
        
    }
};
// @lc code=end

