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
int f[203][203],a[203][203];
int main(){
    int n,m;
    cin>>n>>m;
    rep(i,1,n)
        rep(j,1,m) cin>>a[i][j];
    

    int mmax = -1;
    for(int i = 1;i<=n;++i){
        f[i][1] = max(f[i-1][1],f[i-1][2])+a[i][1];
    
        rep(j,1,m){
            f[i][j] = max(f[i-1][j],max(f[i-1][j-1],f[i-1][j+1]))+a[i][j];
            
        }
        f[i][m] = max(f[i-1][m],f[i-1][m-1])+a[i][m];
    
    }


    cout<<max(f[n][m/2],max(f[n][m/2+2],f[n][m/2+1]))<<endl;
	return 0;
}