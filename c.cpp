// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

int ally1(long long int n);
int ally2(long long int n);

int main() 
{ 
    long long int t;
    cin>>t;
    while(t--)
    {
        if(ally1(t)!=ally2(t)) {
            cout<<ally1(t)<<" "<<ally2(t)<<endl;
            cout<<t<<endl;
        }
    }
    return 0; 
} // } Driver Code Ends


long long int gn(string& num,long long  mini,long long  limit,long long  index){
    if(index == num.size()) return 1;
    if(limit<mini) return 0;
    //cout<<mini<<" "<<limit<<" "<<index<<endl;
    long long int ans = 0;
    for(long long  i=mini;i<limit;i++){
        ans += gn(num,i,9,index+1);
    }
    if(limit==num[index]-'0')
    ans += gn(num,limit,num[index+1]-'0',index+1);
    else ans += gn(num,limit,9,index+1);
    return ans;
}

int ally1(long long int n) {
    // code here 
    //string num = to_string(n);
    //return gn(num,0,num[0]-'0',0)-1;
    int result = 0; 
    for (int i = 1; i <= 9; i++) 
    { 
        stack<long long int> s; 
        if (i <= n) 
        { 
            s.push(i); 
            result++; 
        } 
        while (!s.empty()) 
        { 
            long long int tp = s.top(); 
            s.pop(); 
            for (long long int j = tp%10; j <= 9; j++) 
            { 

                long long int x = tp*10 + j; 
                if (x <= n) 
                { 
                    s.push(x); 
                    result++; 
                }
                else
                    break;
            } 
        } 
    } 
    return result; 
    
}
int ally2(long long int n) {
    // code here 
    string num = to_string(n);
    return gn(num,0,num[0]-'0',0)-1;
}