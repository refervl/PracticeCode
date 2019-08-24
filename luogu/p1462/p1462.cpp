#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector> 
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
int c[10005],v[10005];
LL d[10005][2];
struct city{
	int ccity,cost;
};
vector<city> a[10005];
int main(){
	int n,m,b;
	cin>>n>>m>>b;
	rep(i,1,n) cin>>c[i];
	int to,from,f;
	rep(i,1,n){
		cin>>to>>from>>f;
		if(to==from)  continue;
		a[to].push_back({from,f});
		a[from].push_back({to,f});
	}
	
	
	LL ans = 0;
	rep(i,1,n){
		int mmin = 0x3f3f3f3f,p;
		rep(j,1,n){
		if(c[i]<mmin&&v[j]==0) {mmin = c[i];p = j;}
		}
		v[p] = 1;
		ans= max((LL)mmin,ans);
		rep(j,1,a[p].size()){
			if(d[j][1]+a[p][j].cost>=b) continue;
			if(d[j][0]>mmin+c[j]){
				d[j][0] = mmin+c[j];
				d[j][1] += a[p][j].cost; 
			}
		}
	}
	cout<<ans<<endl;
	return 0;	
} 

