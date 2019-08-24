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
struct node{
	ll a,b,c;
	bool operator < (node const &r) const{
		return this->c*r.b<this->b*r.c;
	}
}d[100003];
ll f[100003];
int main(){
	int t,n;
	cin>>t>>n;
	rep(i,1,n) cin>>d[i].a;
	rep(i,1,n) cin>>d[i].b;
	rep(i,1,n) cin>>d[i].c;
	sort(d+1,d+1+n);
	ll ans = -1;
	rep(i,1,n){
		for(int j = t;j>=d[i].c;j--){
			f[j] = max(f[j],f[j-d[i].c]+d[i].a-j*d[i].b);
			ans = max(ans,f[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}