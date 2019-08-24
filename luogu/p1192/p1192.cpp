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
int a[1000005]; 
int main(){
	a[1] = 1;
	a[0] = 1;
	int n,m;
	cin>>n>>m;
	rep(i,2,n){
		rep(j,1,min(m,i)){
			a[i] +=a[i-j]%100003;
			a[i]%=100003;
		}
	}
	cout<<a[n]<<endl;
	return 0;	
} 

