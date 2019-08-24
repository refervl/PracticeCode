#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
int f[2000],fl[2000],t[105];
int main(){
	int l;
	cin>>l;
	int s,e,m;
	cin>>s>>e>>m;
	rep(i,1,m) cin>>t[i];
	sort(t+1,t+m+1);
	int c = 0;
	rep(i,1,2000) f[i] = 999999999;
	f[0] = 0;
	rep(i,1,m){
		if(t[i]-t[i-1]>2*e) c+=(t[i]-t[i-1])%e+e;
		else c+=t[i]-t[i-1];

		fl[c] = 1; 
	}
	rep(i,1,c+2*e)
		rep(j,s,e) if(i>=j)	f[i] = min(f[i],f[i-j]+fl[i]);
	int ans = 99999999;
	rep(i,c,c+2*e) ans = min(f[i],ans);
	
	cout<<ans<<endl;
	return 0;	
} 

