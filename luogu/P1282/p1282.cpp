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
int f[1003][10006];
int x[1003],y[1003];
int main(){
    int n;
    
    cin>>n;
    rep(i,1,n) cin>>x[i]>>y[i];
    For(i,0,n) rep(j,0,10000) f[i][j] = 9999999;
    f[0][5000] = 0;
    rep(i,1,n)
        rep(j,0,10000){
            int t = x[i]-y[i];
            f[i][j] = min(f[i-1][j+t],f[i-1][j-t]+1);
        }
    For(i,0,5000){
        int ans = min(f[n][5000-i],f[n][5000+i]);
        if(ans<=1000) {
            cout<<ans<<endl;
            break;
        }
    }
	return 0;
}