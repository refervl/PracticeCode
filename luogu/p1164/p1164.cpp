#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
int dp[10005],a[105];
int main(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	
	rep(i,1,n)
		for(int j = m;j>=a[i];j--){
			if(j==a[i]) dp[j] = dp[j]+1;
			if(j>a[i]) dp[j] = dp[j]+dp[j-a[i]];
			if(j<a[i]) dp[j] = dp[j];	
		}
		cout<<dp[m]<<endl;
	return 0;	
} 

