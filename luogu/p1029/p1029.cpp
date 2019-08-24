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

int x,y;
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    cin>>x>>y;
    int n = sqrt(x*y);
    int ans = 0;
    
    rep(i,1,n){
        if((x*y)%i==0&&(gcd(i,x*y/i)==x)) ans++;
    }
    cout<<ans*2<<endl;
	return 0;
}

