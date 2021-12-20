#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int sumOfDigi(int inputNum,int base)
{
    int res = 0;
    while (inputNum > 0)
    {
        res += inputNum % base;
        inputNum /= base;
    }
    return res;
}
int nth_root(int num,int n){
    double low = 1;
    double high = num;
    while(high - low>0.01){
        double mid = (low+high)/2;
        if(pow(mid,n)>num){
            high = mid;
        }else low = mid;
    }
    return high;
}

int fast_appo(int n,int l,int r){
    int ans=0;
    int min_sum = n;
    for(int i=1;i<35;i++){
        int root = nth_root(n,i);
        if(root<l || root>r || root<=1) continue;
        int sum = sumOfDigi(n,root);
        if(min_sum>sum){
            min_sum = sum;
            ans = root;
        }
    }
    int s1=INT_MAX;
    if(l>1)
    s1 = sumOfDigi(n,l);
    int s2=INT_MAX;
    if(r>1)
    s2 = sumOfDigi(n,r);
    if(min_sum>s1){
        min_sum = s1;
        ans = l;
    }
    if(min_sum>s2){
        min_sum = s2;
        ans =r;
    }
    return min_sum;
}
int slow_af(int n,int l,int r){
    int ans = 0;
    int min_sum =  n;
    for(int i=max(l,2);i<=r;i++){
        int sum = sumOfDigi(n,i);
        if(min_sum>sum){
            min_sum = sum;
            ans = i;
        }
    }

    return min_sum;
}
int slow_af_fast(int n,int l,int r){
    int ans = 0;
    int min_sum =  n;
    int sq = sqrt(n);
    if(sq>=l && r>=sq){
        r = sq;
    }
    for(int i=max(l,2);i<=r;i++){
        int sum = sumOfDigi(n,i);
        if(min_sum>sum){
            min_sum = sum;
            ans = i;
        }
    }

    return min_sum;
}
int main()
{
    fast;
    int t=10000;
    //cin>>t;
    while (t--)
    {
        int n,l,r;
        //cin>>n>>l>>r;
        n = rand()%10;
        l = rand()%10;
        r = l + rand()%10;
        int a1 = slow_af_fast(n,l,r);
        int a2 = slow_af(n,l,r);
        if(a1!=a2){
            cout<<"HERE:"<<n<<" "<<l<<"-"<<r<<" fast: "<<a1<<" slow: "<<a2<<endl;
        }
        //cout<<"donee"<<endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9+7;
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// typedef long long int ll;
// int main()
// {
//     fast;
//     int t;
//     cin>>t;
//     while (t--)
//     {
//         int n,l,r;
//         cout<<slow_af_fast(n,l,r)<<endl;
//     }
//     return 0;
// }