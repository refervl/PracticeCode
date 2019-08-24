#include<iostream>
using namespace std;
int a[10] = {2,3,5,7,11,13,17,19,23,29};
int n,ans = 0,maxn = -1;
void solve(int n1,int num,int p,int mm){
	
	if(num > maxn||(num==maxn&&n1<ans)){
		ans = n1;
		maxn = num;
	}
	
	int x = n1,i = 0;
	while(i<mm){
		i++;
		if(n/x<a[p]) break;
		int num1 = num*(i+1);
		x*=a[p];
		if(n>=x) solve(x,num1,p+1,i);	
	}
}
int main(){
	cin>>n;
	solve(1,1,0,33);
	cout<<ans<<endl;
return 0;	
}
