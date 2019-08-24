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
int c[16][16],a[14];
int main(){
    int n,sum;
    cin>>n>>sum;
    rep(i,1,n) a[i]  = i;

    c[0][0] = 1,c[1][0] = 1,c[1][0] = 1;
    
    rep(i,2,12)
        rep(j,0,i) if(j==0) c[i][j] = 1;
                    else c[i][j] = c[i-1][j]+c[i-1][j-1];
    int ans;
    do{
        ans = 0;
        rep(i,0,n-1) ans+=c[n][i]*a[i+1];
        if(ans==sum) {
            rep(i,1,n) cout<<a[i]<<' ';
            break;
        }
    }while(next_permutation(a+1,a+n+1));
    return 0;
}

