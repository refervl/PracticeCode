#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
#define inf 1000001
int d[103][103];

int main(){
	int n,s,e;
	cin>>n>>s>>e;
	rep(i,1,n)
		rep(j,1,n) {d[i][j] = inf;d[i][i] = 0;}
	
	int t,tt;
	rep(i,1,n){
		cin>>t;
		rep(j,1,t){
			cin>>tt;
			if(j==1) d[i][tt] = 0;
			else d[i][tt] = 1; 
		}
	}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
	if(d[s][e]!=inf)
	cout<<d[s][e]<<endl;
	else cout<<-1<<endl;
	return 0;	
} 

