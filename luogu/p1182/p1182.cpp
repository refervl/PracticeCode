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
int n,m,a[100003];
inline int check(int x){
    int ans = 0,sum=0;
    For(i,0,n) if(sum+a[i]<=x) sum+=a[i];
    else {sum=a[i];ans++;}
    return ans>=m;
}
int main(){
	cin>>n>>m;
    int mmax = 0,left = -1;
    For(i,0,n) {
        cin>>a[i];
        mmax+=a[i];
        left = max(left,a[i]);
        
    }

    while(left<=mmax){
        int mid = (left+mmax)>>1;
        if(check(mid)) left = mid+1;
        else mmax = mid-1;
    }
    cout<<left<<endl;
	return 0;
}