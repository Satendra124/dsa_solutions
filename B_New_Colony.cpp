#include<iostream>
using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    for(int e=0;e<testcases;e++){
        
        int n,k;
        cin >> n >> k;
        
        int a[n+1]={0};
        for (int i = 0; i < n; ++i) {cin >> a[i];}
        

        for(int i=1;i<=k;)
        {
            int pos=0;
            while(a[pos]>=a[pos+1]) { pos++;}
            if (pos==n) {
                cout << "-1" <<endl;
                break;  }

            a[pos] = a[pos]+1;
            i++;

            if (i>k){
                cout<<pos+1<<endl;
            }
        }
        
    }
    return 0;
}