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
int f[20005],vv[33];
int main(){
	int v,n;
	cin>>v>>n;
	rep(i,1,n) cin>>vv[i];
	rep(i,1,n)
		for(int j = v;j>=vv[i];j--)
			f[j] = max(f[j],f[j-vv[i]]+vv[i]);
	cout<<v-f[v]<<endl; 
	return 0;	
} 

