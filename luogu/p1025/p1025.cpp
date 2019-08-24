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

int c = 0;	int n,m;
void solve(int total,int n1,int s){
	
	if(n1==0) {if(total==0) c++;return;}
	
	for(int i = s;total-i*n1>=0;++i){
		
		solve(total-i,n1-1,i);
	}
	
}
int main(){

	cin>>n>>m;
	solve(n,m,1);
	cout<<c<<endl;
	return 0;	
} 

