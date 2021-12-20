
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
    
	while(q--){
		int queryInt;
		cin>>queryInt;
		if(queryInt==1){
			char c;
			cin>>c;
			s.push_back(c);
		}else if(queryInt==2){
            int ans = 0;
			int x,y;
			cin>>x>>y;
			//these are three pointers
			x--;
			y--;
			int a=1,b=x,c=y;
			while(a<s.length()&&b>=0&&c>=0){
				if(s.substr(0,a).compare(s.substr(b,a))&&s.substr(b,a).compare(s.substr(c,a))){
					ans = a;
				}
				a++;
				b--;
				c--;
			}
            cout<<ans-1<<endl;
		}else{
			int p,l,r;
			cin>>p>>l>>r;
			string toSearch = s.substr(0,p);
			string mainString = s.substr(l-1,l-r+1);
			int ans = 0;
			for(int i=0;i<mainString.length()-p;i++){
				if(mainString.substr(i,p).compare(toSearch)==0){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
        
	}
}