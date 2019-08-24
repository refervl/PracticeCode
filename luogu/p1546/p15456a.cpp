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
struct node{
	int x1,x2,l;
	 bool operator <(const node&rhs) const{
	 	return l<rhs.l;
	 }
}a[10003];
int f[10003];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	int n;
	cin>>n;
	rep(i,1,n) f[i] = i;
	int t;
	int tot = 0;
	rep(i,1,n)
		rep(j,1,n){
			cin>>t;
			if(i<j){
				a[tot].x1 = i;
				a[tot].x2 = j;
				a[tot++].l = t;
			}
		}
	sort(a,a+tot);
	int ans=0,c=0;
	For(i,0,tot){
		int a1 = find(a[i].x1),b1 = find(a[i].x2);
		if(a1!=b1){
			ans+=a[i].l;
			f[a1] = a[i].x2; 
			c++;
			if(c==n) break;
		}
	}
	cout<<ans<<endl;
	return 0;	
} 

