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
double a[16],x[16],y[16],v[16];double d[16][16];
int n;double mmin = 99999999,dist;
void dfs(int l,int s){
    if(s==n) {mmin = min(mmin,dist);return;}
    if(dist>mmin) return;
    rep(i,1,n){
        if(v[i]) continue;
        dist+=d[l][i];
        v[i] = 1;
        dfs(i,s+1);
        dist-=d[l][i];
        v[i] = 0;
    }
}
int main(){
    cin>>n;
    rep(i,1,n) cin>>x[i]>>y[i];
    rep(i,0,n)
        rep(j,0,n){
            if(i==j) continue;
            d[i][j] = sqrt((y[i]-y[j])*(y[i]-y[j])+(x[i]-x[j])*(x[i]-x[j]));
        }
    dfs(0,0);
    printf("%0.2lf\n",mmin);
	return 0;
}

