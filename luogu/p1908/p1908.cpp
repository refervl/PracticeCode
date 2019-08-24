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
const int maxn = 500003;
int a[maxn],b[maxn];
ll ans;
void solve(int l,int r){
    if(l==r) return;
    ll mid = (l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    int i = l,j = mid+1,k = l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]) b[k++] = a[i++];
        else {
                b[k++] = a[j++];
                ans+=mid-i+1;
    }
    }
    while(i<=mid) b[k++] = a[i++];
    while(j<=r) b[k++]  = a[j++];
    rep(i,l,r) a[i] = b[i]; 
    
}
int main(){
    int n;
    R(n);
    For(i,0,n) R(a[i]);
    solve(0,n-1);
    cout<<ans<<endl;
	return 0;
}

