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
char a[1055];
void solve(int l,int r){
    if(r>l){
        solve(l,(l+r)>>1);
        solve((l+r+1)>>1,r);
    }
    int b=0,I=0;
    rep(i,0,r-l){
        if(a[l+i]=='0') b = 1;
        else I = 1;
    }
    if(b&&!I) cout<<'B';
    else if(I&&!b) cout<<'I';
    else cout<<'F';
}
int main(){
	int n;
    cin>>n;
    cin>>a;
    solve(0,(1<<n)-1);
    cout<<endl;
	return 0;
}