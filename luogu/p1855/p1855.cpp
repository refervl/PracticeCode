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
int f[202][202];
int a[101],b[102];
int main(){
	int n,m,t;
    cin>>n>>m>>t;
    rep(i,1,n) cin>>a[i]>>b[i];
    rep(i,1,n)
        for(int j = m;j>=a[i];j--)
            for(int k = t;k>=b[i];k--)
                {
                    f[j][k] = max(f[j-a[i]][k-b[i]]+1,f[j][k]);
                }
    cout<<f[m][t]<<endl;
	return 0;
}