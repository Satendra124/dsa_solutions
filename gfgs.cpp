// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merge(long long arr[],int start,int mid,int end,int& invCnt){
        int p1 = start,p2=mid+1,p= 0;
        long long ans[end-start+1];
        while(p1<=mid || p2<=end){
            if(p1>mid || arr[p1]>arr[p2]){
                ans[p++] = arr[p2++];
                invCnt += mid+1 - p1;
            }else{
                ans[p++] = arr[p1++];
            }
        }
        for(int i=start,j=0;(i<=end)&&(j<end-start+1);i++,j++){
            arr[i] = ans[j];
        }
    }
    
    void mergesort(long long arr[],int start,int end,int& invCnt){
        int mid = start+ (end-start)/2;
        if(start>=end) return;
        mergesort(arr,start,mid,invCnt);
        mergesort(arr,mid+1,end,invCnt);
        
        merge(arr,start,mid,end,invCnt);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        int invCnt = 0;
        mergesort(arr,0,N-1,invCnt);
        return invCnt;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends