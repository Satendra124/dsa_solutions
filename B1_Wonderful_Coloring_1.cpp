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
        int arr[26];
        memset(arr,0,sizeof(arr));
        string s;
        cin>>s;
        for(char c:s) arr[c-'a']++;
        int uniq = 0;
        int second = 0;
        for (int i = 0; i < 26; i++)
        {
            if(arr[i]>1) second++;
            if(arr[i]>=1) uniq++;
        }
        cout<<(second+uniq)/2<<endl;
        

    }
    return 0;
}