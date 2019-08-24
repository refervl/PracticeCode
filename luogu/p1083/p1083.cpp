#include<iostream>
#include<cstring>
using namespace std;
int a[1000006],a1[10000006],b1[1000006];
struct r{
	int d,s,e;	
}b[1000006];
int n,m;
int is(int d1){
		memset(b1,0,sizeof(b1));
		for(int i = 1;i<=d1;++i){
			b1[b[i].s] +=b[i].d;	
			b1[b[i].e+1]-=b[i].d;
		}
		
		for(int i = 1;i<=n;++i){
			a1[i] = a1[i-1]+b1[i];
			if(a1[i]>a[i]){
				return 0;
			}
		}
	
	return 1;
	
}
int main(){
	
	cin>>n>>m;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	for(int i = 1;i<=m;++i)
		cin>>b[i].d>>b[i].s>>b[i].e;
	
	int s = 1,e = m;
	if(is(m)) cout<<0<<endl;
	else{
	while(s<e){
		
		int m = s+(e-s)/2;
		if(is(m)) s = m+1;
		else e = m;	
	}
		cout<<-1<<endl<<s<<endl;	
	}
return 0;	
}
