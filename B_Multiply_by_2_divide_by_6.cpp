#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        int m = 0;
        while (n%6==0) {
            n /= 6;
            m++;
        }
        while(n%3==0) {
            n *= 2;
            n /=6 ;
            m+=2;
        }
        if(n==1) cout<<m<<endl;
        else cout<<-1<<endl;
        
    }
    return 0;
}