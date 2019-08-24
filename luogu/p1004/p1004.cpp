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
int f[53][53][53][53],a[53][53];
int  mmax(int a1,int a2,int a3,int a4){
    int ans = -1;
    ans = max(ans,a1);
    ans = max(ans,a2);
    ans = max(ans,a3);
    ans = max(ans,a4);
    return ans;
}
int main(){
    int n,m;
    cin>>n;
    int x,y,z;
    while(true){
        cin>>x>>y>>z;
        a[x][y] = z;
        if(x==0&&y==0&&z==0) break;
    }
        rep(i,1,n)
            rep(j,1,n)
                rep(k,1,n)
                    rep(l,j+1,n)
                        f[i][j][k][l] = mmax(f[i-1][j][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k-1][l],f[i][j-1][k][l-1])+a[i][j]+a[k][l];
    cout<<f[n][n-1][n-1][n]<<endl;
	return 0;
}