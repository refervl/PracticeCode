#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>             
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define ll long long
#define INI(x) memset(x,0,sizeof(x))
#define R(x) scanf("%d",&x)
#define W(x) printf("%d\n",x)
#define Rll scanf("%lld",&x)
#define Wll printf("%lld\n",x)
struct node{
	int l,r,c;
}a[40000];
int ans=0;
void build(int l,int r,int k){
	a[k].l=l;
	a[k].r=r;
	a[k].c = 0;
	int m = (l+r)/2;
	if(a[k].l==a[k].r) return ;
	build(l,m,k*2);
	build(m+1,r,k*2+1);
	
}
void add(int left,int right,int k){

	if(a[k].c==1) return ;
	if(a[k].l==left&&a[k].r==right){
		a[k].c=1;
		return ;
	}
	int m = (a[k].l+a[k].r)/2;
	if(left>=m) add(left,right,k*2+1);
	else if(right<m) add(left,right,k*2);
	else{
		add(left,m,k*2);
		add(m,right,k*2+1);
	}
}
void count(int k){
	if(a[k].c==1) ans+=a[k].r-a[k].l+1;
	else if(a[k].r-a[k].l==1) return ;
	else {
		count(k*2);
		count(k*2+1);
	}
}
int main(){
	int n,m;
	R(n);R(m);
	build(1,n,1);
	int x,y;
	For(i,0,m){
		R(x);R(y);
		add(x,y,1);
	}
	count(1);
	W(ans);
		return 0;	
} 

