#include<iostream>

using namespace std;
#define _for(i,a,b) for(int i = (a);i<(b);++i)
int a[100003];
int main(){
	int n,m;
	cin>>n>>m;
	_for(i,0,n) cin>>a[i];
	a[n] = 1<<9;
	int c = 0,t=0;
	_for(i,0,n){
		if(t+a[i]<=m){
			t+=a[i];
			
		}
		else {	c++;
				t=a[i];
				//cout<<c<<' '<<t<<endl;
		}
	}
	cout<<c+1<<endl;
	return 0;
}
