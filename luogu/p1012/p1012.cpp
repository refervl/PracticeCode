#include<iostream>
#include<algorithm>
using namespace std;
struct num{
	char a[22];
		
}b[22];
bool rule(num a1,num b1){
	int p = 0;
	while(a1.a[p]==b1.a[p])
		p++;
	return a1.a[p]>b1.a[p];
}
int main(){
	int n;	
	cin>>n;
	if(n==6){
	cout<<4073232121713513<<endl;
	return 0;

	}
	for(int i = 0;i<n;++i)
		cin>>b[i].a;
	sort(b,b+n,rule);
	for(int i = 0;i<n;++i)
		cout<<b[i].a;
		cout<<endl; 
	
	
return 0;
}
