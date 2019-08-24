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
int a[100003],n,m;
inline int check(int x){
    int sum=0,ans=1;
    For(i,1,n) if(a[i]-a[sum]>=x){ans++;sum = i;}
  
    return ans>=m;
}
int main(){
	cin>>n>>m;
    For(i,0,n) cin>>a[i];
    sort(a,a+n);
    int left = 0,right = a[n-1]-a[0];
    while(left<=right){
        int mid = (left+right)>>1;
        if(check(mid)) left = mid+1;
        else right = mid-1;
    }
    cout<<left-1<<endl;
	return 0;
}