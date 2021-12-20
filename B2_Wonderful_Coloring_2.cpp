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
        int n,k;
        cin>>n>>k;
        int arr[n];
        int maxNum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            maxNum = max(maxNum,arr[i]);
        }
        int rec[maxNum+1];
        memset(rec,0,sizeof(rec));
        int asign[n];
        int minFill = 1;
        int minFills = 0;
        int cont[k+1];
        memset(cont,0,sizeof(cont));
        int nopaint = 0;
        for (int i = 0; i < n; i++)
        {
            int asignNum = rec[arr[i]] +1;
            if(asignNum>k) {
                asign[i] = 0;
                nopaint++;
            }else{
                asign[i] = asignNum;
                rec[arr[i]] = asignNum;
            }
        }
        memset(rec,0,sizeof(rec));
        int req = (n - nopaint)/k;
        for (int i = 0; i < n; i++)
        {
            int asignNum = rec[arr[i]] +1;
            if(asignNum>k || minFill>k) {
                asign[i] = 0;
            }else{
                if(asignNum<=minFill){
                    asign[i] = minFill;
                    rec[arr[i]] = minFill;
                    cont[minFill]++;
                    minFills++;
                    if(minFills==req) {
                        minFill++;
                        minFills=cont[minFill];
                    }
                }else{
                    asign[i] = asignNum;
                    rec[arr[i]] = asignNum;
                    cont[asignNum]++;
                } 
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<asign[i]<<" ";
        }
        cout<<endl;
        
        

    }
    return 0;
}