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
int f[2503][2503],a[2503][2503],x1[2503][2503],x2[2503][2503];
int main(){
    int n,m;
    cin>>n>>m;
    rep(i,1,n)
        rep(j,1,m) cin>>a[i][j];
    int ans = -1;
    rep(i,1,n)
        rep(j,1,m){
            if(!a[i][j]){x1[i][j] = x1[i-1][j]+1;x2[i][j] = x2[i][j-1]+1;}
            else {f[i][j] = min(f[i-1][j-1],min(x1[i-1][j],x2[i][j-1]))+1;}
            ans = max(f[i][j],ans);
        }
    
    INI(x1),INI(x2),INI(f);
    rep(i,1,n)
        for(int j = m;j>=1;j--){
            if(!a[i][j]){x1[i][j] = x1[i-1][j]+1;x2[i][j] = x2[i][j+1]+1;}
            else {f[i][j] = min(f[i-1][j+1],min(x1[i-1][j],x2[i][j+1]))+1;}
            ans = max(f[i][j],ans);
        }
        cout<<ans<<endl;
	return 0;
}