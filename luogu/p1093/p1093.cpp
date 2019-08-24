#include<iostream>
#include<algorithm>
using namespace std;
struct p{
	int c,m,e,n;
	int t;
}a[303];
bool rule(p a,p b){
	if(a.t==b.t){
			if(a.c==b.c) return a.n<b.n;
			return a.c>b.c;
}
	return a.t>b.t;
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i<n;++i){
		cin>>a[i].c>>a[i].m>>a[i].e;
		a[i].t=a[i].c+a[i].m+a[i].e;
		a[i].n = i+1;}
		
	sort(a,a+n,rule);
	for(int i = 0;i<5;++i)
		cout<<a[i].n<<' '<<a[i].t<<endl;
return 0;	
}
