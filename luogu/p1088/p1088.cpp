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
int a[10003];
int main(){
    int n,m;
    cin>>n>>m;
    For(i,0,n) cin>>a[i];
    while(m--) next_permutation(a,a+n);
    For(i,0,n) cout<<a[i]<<' ';
    cout<<endl;


	return 0;
}

