#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define _for(i,a,b) for(int (i)= (a);i<(b);++i)
#define _rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
int y[1000005];
int main(){
	INI(y);
	int n,t,mm=0;
	cin>>n;
	_for(i,0,n){
		cin>>t;
		mm = max(mm,t);
		int m = sqrt(t);
		_rep(j,1,m){
			
			if(t%j==0){
				{y[j]++;}
			if(j*j!=t) {y[t/j]++;}
			}
		}
	}

	_rep(i,1,n){
		while(y[mm]<i) mm--;
		cout<<mm<<endl;
	}
return 0;	
} 

