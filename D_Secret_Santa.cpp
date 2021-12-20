#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

//fix problem of people who are lonly as well as fokat

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        map<int,int> santas;
        map<int,vector<int>> lovers;
        map<int,int> bestlovers; //lonely are best lovers
        vector<int> fokats;
        vector<int> lonely;
        int happiness = n;
        for (int i = 1; i <= n; i++)
        {
            lovers[arr[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            //if no lover add lover
            // if there is lover replace if current is not lonley
            if(bestlovers.find(arr[i])==bestlovers.end()){
                bestlovers[arr[i]] = i;
            }else{
                //compete here
                if(lovers[bestlovers[arr[i]]].size()>0) {
                    fokats.push_back(bestlovers[arr[i]]);
                    bestlovers[arr[i]] = i;
                    happiness--;
                }else if(lovers[i].size()==0){
                    //isko sathi mil gya 
                    bestlovers[bestlovers[arr[i]]] =i;
                    lovers[bestlovers[arr[i]]].push_back(i);
                    happiness--;
                }else{
                    fokats.push_back(i);
                    happiness--;
                }
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            //decide i ko kon lover gift dega
            //the best lover will gift
            if(bestlovers.find(i)!=bestlovers.end()){
                santas[i] = bestlovers[i];
            }
            
        }
        for (int i = 1; i <= n; i++)
        {
            if(santas.find(i)==santas.end()){
                lonely.push_back(i);
            }
        }
        //match lonley with fokat
        for (int i = 0; i < fokats.size(); i++)
        {
            santas[lonely[i]] = fokats[i];
        }
        cout<<happiness<<endl;
        map<int,int> pyar;
        for (int i = 1; i <= n; i++)
        {
            pyar[santas[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            cout<<pyar[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}