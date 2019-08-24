#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>            
#include<stack>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define ll long long
#define INI(x) memset(x,0,sizeof(x))
#define R(x) scanf("%d",&x)
#define W(x) printf("%d\n",x)
#define Rll(x) scanf("%lld",&x)
#define Wll(x) printf("%lld\n",x)
#define pb push_back
const int maxn = 4000003;
int a[maxn],b[maxn],f[maxn];int n,m;
int main(){
	cin>>n>>m;
	int t,mmax = -1;
	For(i,0,n){
		cin>>t;
		a[t]++;
		b[t]+=t;
		mmax = max(t,mmax);
	}
	For(i,1,mmax+m) {a[i]+=a[i-1];b[i]+=b[i-1];}
	rep(i,0,mmax+m) f[i] = 99999999;
	For(i,0,mmax+m){
		if(i>m) if(a[i]==a[i-m]){f[i]= f[i-m]; continue;}
		int j = max(i-m-m+1,0);
		f[i] = a[i]*i-b[i];
		for(;j<=i-m;j++){
			f[i] = min(f[i],f[j]+(a[i]-a[j])*i-b[i]+b[j]);
		}
	}
	int ans = f[mmax];
	rep(i,mmax,mmax+m) ans = min(ans,f[i]);
//	rep(i,1,n+m) cout<<f[i]<<endl;
	cout<<ans<<endl;
	return 0;
}

