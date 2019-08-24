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
int f[42][42][42][42],w[6],a[370];
int main(){
    int n,m,t;
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    For(i,0,m){
        cin>>t;
        w[t]++;
    }
    f[0][0][0][0] = a[1];
     rep(i,0,w[1])
        rep(j,0,w[2])
            rep(k,0,w[3])
                rep(l,0,w[4]){
                    int res = 1+i+2*j+3*k+4*l;
                    if(i) f[i][j][k][l] = max(f[i-1][j][k][l]+a[res],f[i][j][k][l]);
                    if(j) f[i][j][k][l] = max(f[i][j-1][k][l]+a[res],f[i][j][k][l]);
                    if(k) f[i][j][k][l] = max(f[i][j][k-1][l]+a[res],f[i][j][k][l]);
                    if(l) f[i][j][k][l] = max(f[i][j][k][l-1]+a[res],f[i][j][k][l]);
                }
    cout<<f[w[1]][w[2]][w[3]][w[4]]<<endl;
	return 0;
}