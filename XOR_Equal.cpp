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
        ll n,x;
        cin>>n>>x;
        map<ll,int> m_ini;
        vector<ll> arr;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
            m_ini[temp]++;
        }
        int max_cnt = 0;
        int ops = 0;
        for(ll i:arr){
            if((i!=i^x)&& max_cnt < m_ini[i] + m_ini[i^x]){
                max_cnt = m_ini[i] + m_ini[i^x];
                ops = m_ini[i^x];
            }else if((i!=i^x)&& max_cnt == m_ini[i] + m_ini[i^x] && ops>m_ini[i^x]){
                max_cnt = m_ini[i] + m_ini[i^x];
                ops = m_ini[i^x];
            }
            else if(max_cnt<m_ini[i]){
                max_cnt = m_ini[i];
                ops = 0;
            }
        }
        cout<<max_cnt<<" "<<ops<<endl;
        


    }
    return 0;
}