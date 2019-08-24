#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define _rep(i,a,b) for(int i = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
struct p{
	int x,c;
}a[5005];
bool rule(p a,p b){
	return a.x<b.x;	
}
int main(){
	int n,m;
	cin>>n>>m;
	_for(i,0,m)
		cin>>a[i].x>>a[i].c;
	sort(a,a+m,rule);
	int ans = 0,cc=0,i=0;
	while(true){
		if(cc+a[i].c>=n){
			ans+=a[i].x*(n-cc);
			break;
		}
		cc+=a[i].c;
		ans+=a[i].x*a[i].c;
		++i;
	}
	cout<<ans<<endl;		
return 0;	
} 

