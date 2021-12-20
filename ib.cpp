#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

bool sortFncs(int & a,int & b){
    string A = to_string(a);
    string B = to_string(b);
    int i=0,j=0;
    int n = A.length(),m = B.length();
    while(i<n&&j<m){
        if(A[i]==B[j]) {
            i++;j++;
            continue;
        }
        else{
            return A[i]>B[j];
        }
    }
    while(i<n||j<m){
        if(i==n&&j==m) break;
            else{
                if(i==n) i = 0;
                else if(j==m) j =0;
            }
        if(A[i]==B[j]){
            i++;
            j++;
        } else return A[i]>B[j];
    }
    if(i==n) return true;
    else return false;
    //return (a>b);
}

string largestNumber(const vector<int> &A) {
    vector<int> B =A;
    sort(B.begin(),B.end(),sortFncs);
    string s = "";
    for(int i=0;i<B.size();i++) s.append(to_string(B[i]));
    return s;
}
vector<int> dp;
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),greater<vector<int>>());
        dp = vector<int>(envelopes.size(),-1);
        
    }
int sqroot(int A) {
    int l = 1;
    int r = A;
    int ans = 0;
    while(l<=r){
        long long int mid = l + (r-l)/2;
        long long int no = mid*mid;
        if(no>A) r = mid -1;
        else if(no==A) return mid;
        else{
            ans = mid;
            l = mid+1;
        }
    }
    return ans;
}


int main()
{
    fast;
    int n;
    cin>>n;
    cout<<sqroot(n)<<endl;
    
    return 0;
}