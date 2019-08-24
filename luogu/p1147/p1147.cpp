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

int main(){
    int m;
    cin>>m;
    int x = sqrt(m);
    for(int i = m-1;i>=2;i--){
        if(m%i==0&&i%2){
        if(m/i-i/2>0) cout<<m/i-i/2<<' '<<m/i+i/2<<endl;
            
        }
        if((m/i)*i-m==-(0.5*i)){
           if(m/i-i/2>0) cout<<m/i-i/2+1<<' '<<m/i+i/2<<endl;
        }
    }

	return 0;
}