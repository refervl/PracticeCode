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
int dp[30005],v[30005],w[30005];
int main(){
	int n,t;
	cin>>n>>t;
	For(i,0,t) {cin>>v[i]>>w[i];w[i]*=v[i];}
	
	For(i,0,t) 
		for(int j = n;j>=v[i];j--)
			if(j>=v[i])
				dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
		cout<<dp[n]<<endl;
	return 0;	
} 

