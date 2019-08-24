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
int dp[203][8];
int main(){
	int n,m;
	cin>>n>>m;
	INI(dp);
	rep(i,1,n) dp[i][1] = 1;
	rep(i,2,m) {dp[1][i] = 0;dp[0][i] = 0;}

		
		rep(i,1,n)
			rep(j,2,m) 
				if(i<=j) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = dp[i-1][j-1]+dp[i-j][j];
	cout<<dp[n][m]<<endl;
	return 0;	
} 

