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
ll b,k,p;
ll q_pow(ll n,ll base){
    ll ans = 1;
    while(n){
        if(n&1) {ans *= base;ans%=p;}
        base*=base;
        base%=p;
        n>>=1; 
        
    }
    return ans;
}
int main(){

    cin>>b>>k>>p;
     printf("%lld^%lld mod %lld=",b,k,p);
    printf("%lld\n",(q_pow(k,b)%p));

	return 0;
}

