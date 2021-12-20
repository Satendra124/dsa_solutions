#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        string ans = "";
        int div = sqrt(n);
        ans.append(to_string(div));
        ans.push_back('.');
        int cur = n - div;
        if(div>cur)
        cur *= pow(10,log10(div/cur)+1);
        while (d--)
        {
            div = 2*div*10;
            int z = log10(div/cur);
            if(z>0){
                div /=20;
                ans.push_back('0');
                cur *=10;
                continue;
            }
            cur *= pow(10,z+1);
            int v = 0;
            for (int i = 1; i < 10; i++)
            {
                if((div+i)*i>=cur){
                    v = i-1;
                    break;
                }
            }
            ans.push_back(v+'0');
            div = div+v;
            cur -= v * div;
        }
        if(cur!=0) ans[ans.size()-1]++;
        cout<<ans<<endl;
    }
    return 0;
}