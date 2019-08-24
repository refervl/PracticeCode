#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>            
#include<stack>
#include<map>
#include<set>
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
int f[103][103],a[103][103];
int main(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
		rep(j,1,m) cin>>a[i][j];
		int mmax = -1;
	rep(i,1,n)
		rep(j,1,m){
			if(a[i][j]) f[i][j] = min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
			mmax = max(f[i][j],mmax);
		}
	cout<<mmax<<endl;
	return 0;
}