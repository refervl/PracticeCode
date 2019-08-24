#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
int a[200005],b[200005]; 
int main(){
	int n;
	cin>>n;
	rep(i,1,n){
		a[i] = i;
		cin>>b[i];
		a[i] = b[i];
	}
	int m = 999999,c,k;
	rep(i,1,n){
		k = i;
		c=0;
		rep(j,1,n){
			k = a[k];
			if(k==i) {m = min(c+1,m);break;}
			else c++;
		}
	
	} 
	cout<<m<<endl;

return 0;	
} 

