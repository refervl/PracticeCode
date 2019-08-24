#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define _rep(i,a,b) for(int i = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))

int main(){
	LL n;
	cin>>n;
	_rep(i,1,sqrt(n)){
		LL ans = i*i;
		cout<<ans<<' ';	
	}
	
return 0;	
} 

