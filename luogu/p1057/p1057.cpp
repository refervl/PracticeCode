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
int f[33][33];
int main(){
    int n,m;
    cin>>n>>m;
    f[1][0] = 1;
    
    rep(i,1,m){
        f[1][i] = f[n][i-1]+f[2][i-1];
        rep(j,2,n-1){
            f[j][i] = f[j+1][i-1]+f[j-1][i-1];
        }
        f[n][i] = f[n-1][i-1]+f[1][i-1];
    }
        cout<<f[1][m]<<endl;

    
	return 0;
}

