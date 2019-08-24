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

int main(){
	int n;
    cin>>n;
    int t,sum=0,mmax = -9999999;
    For(i,0,n) {
        cin>>t;
        mmax = max(sum+t,mmax);
        if(sum+t<0) sum = 0;
        else{sum+=t;}
    }
    cout<<mmax<<endl;
	return 0;
}