#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int l[10000],v[10000],a[10000];
int main(){
	freopen("testdata(4).in","r",stdin);
	int L,s,t,m,t2,c=0;
	cin>>L>>s>>t>>m;
	if(s==t){
		for(int i = 0;i<m;++i){
		cin>>t2;
		c+=((t2%s)==0);
	}
	cout<<c<<endl;
	
	}
	else {
	for(int i = 1;i<=m;++i)
		cin>>a[i];
	int mm = t*(t-1);
	a[0] = 0;
	int p=0;
	memset(v,0,sizeof(v));
	sort(a+1,a+m+1);
	for(int i = 1;i<=m;++i){
		
		if(a[i]-a[i-1]>mm)
			v[p+=mm] = 1;	
		else v[p+=a[i]-a[i-1]] = 1;
	}
	
	p+=min(mm,L-p);
	l[0] = 99999;
	int mmin = 99999;
	for(int i = 1;i<=p+t;i++){
		l[i] = 999998;
		if(i>=s)
		for(int j = s;j<=t;j++) 	{l[i] = min(l[i-j]+v[i],l[i]);}
	} 
	for(int i =p;i<=p+t;++i) mmin = min(mmin,l[i]);
	cout<<mmin<<endl;
	
	fclose(stdin);
}
return 0;	
}
