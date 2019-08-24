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
int dp[32003],m1_v[63],m1_w[63],m2_v[63][3],m2_w[63][3];
int main(){
	int n,m;
	int mv,mw,g;
	cin>>m>>n;
	rep(i,1,n){
		cin>>mv>>mw>>g;
		if(g==0){
			m1_v[i] = mv;
			m1_w[i] = mv*mw;
		}
		else{
			m2_v[g][0]++;
			m2_v[g][m2_v[g][0]] = mv;
			m2_w[g][m2_v[g][0]] = mw*mv;
		}
	}
	
	rep(i,1,n)
		for(int j = m;m1_v[i]!=0&&j>=m1_v[i];j--){
			
			dp[j] = max(dp[j],dp[j-m1_v[i]]+m1_w[i]);
			
			if(j>=m2_v[i][1]+m1_v[i])
				dp[j] = max(dp[j],dp[j-m1_v[i]-m2_v[i][1]]+m2_w[i][1]+m1_w[i]);
				
			if(j>=m2_v[i][2]+m1_v[i])
				dp[j] = max(dp[j],dp[j-m1_v[i]-m2_v[i][2]]+m2_w[i][2]+m1_w[i]);
				
			if(j>=m2_v[i][1]+m2_v[i][2]+m1_v[i])
				dp[j] = max(dp[j],dp[j-m1_v[i]-m2_v[i][1]-m2_v[i][2]]+m2_w[i][1]+m2_w[i][2]+m1_w[i]);
			
		}
	cout<<dp[m]<<endl;
	return 0;	
} 

