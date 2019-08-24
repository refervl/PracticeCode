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
int a[203],f[203][203];
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		a[i+n] = a[i];
	}
	rep(i,2,n){
		rep(j,1,2*n-i)
			rep(k,j,j+i-2)
				f[j][j+i-1] = max(f[j][j+i-1],f[j][k]+f[k+1][j+i-1]+a[j+i]*a[j]*a[k+1]);

	}
	int an = 0;
	rep(i,1,n) if(f[i][i+n-1]>an) an = f[i][i+n-1];
	cout<<an<<endl;
	return 0;
}