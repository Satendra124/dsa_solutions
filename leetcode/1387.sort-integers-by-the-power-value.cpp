/*
 * @lc app=leetcode id=1387 lang=cpp
 *
 * [1387] Sort Integers by The Power Value
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    static int steps(int n){
        int s = 0;
        while (n!=1)
        {
            if(n%2) n = 3*n+1;
            else n/=2;
            s++;
        }
        return s;
    }
    static bool compfn(int a,int b){
        int A = steps(a);
        int B = steps(b);
        if(A<B) return true;
        else if(A==B) return a<b;
        else return false;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> arr;
        for (int i = lo; i <= hi; i++)
        {
            arr.push_back(i);
        }
        sort(arr.begin(),arr.end(),compfn);
        // for (int i = 0; i <arr.size(); i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        return arr[k-1];
    }
};
// @lc code=end

