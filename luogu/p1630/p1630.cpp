#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define _rep(i,a,b) for(int i = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
#define mod 10000
int ans[10003];
int solve(LL a,LL b){
	LL s= 1;
	while(b){
		if(b%2==1){
			s = (s*a)%mod;	
		}
		a = (a*a)%mod;
		b/=2;
	}
	return s;
}
int main(){
	INI(ans);
	int n;
	cin>>n;
	LL a,b;
	while(n--){
		cin>>a>>b;
		_rep(i,1,10000)
			ans[i] = (ans[i-1]+solve(i,b))%mod;
		
		int ans1 = a/mod*ans[mod]+ans[a%mod]%mod;
		cout<<ans1<<endl;
	}
return 0;	
} 

