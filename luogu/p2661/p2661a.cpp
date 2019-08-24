#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
int a[200005],f[200005],c[200005];
int n,ans;
int find(int x){
	int fa = f[x];
	if(f[x]!=x){
		f[x] = find(f[x]);
		c[x]+=c[fa];	
	}
	return f[x];	
}


void solve(int x,int y){
	int a = find(x),b = find(y);
	if(a==b) ans = min(ans,c[x]+c[y]+1);
	else {f[a] = b; c[x]=c[y]+1;}
	return;	
		
}

int main(){
	ans = 9999999;
	cin>>n;
	rep(i,1,n) f[i] = i;
	rep(i,1,n) {cin>>a[i];
		solve(i,a[i]);}
	cout<<ans<<endl;
	
	
return 0;	
} 

