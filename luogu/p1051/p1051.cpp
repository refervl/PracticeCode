#include<iostream>
#include<algorithm>
using namespace std;
struct p{
	char a[22];
	int f,c,pa,num;
	char gb,xi;
	int ans=0;
}w[105];
bool rule(p a,p b){
 		
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i<n;++i){
		cin>>w[i].a>>w[i].f>>w[i].c>>w[i].gb>>w[i].xi>>w[i].pa;
			w[i].num=i;
		}
	int tot=0;
	for(int i = 0;i<n;++i){
		if(w[i].f>80&&w[i].pa>=1) {w[i].ans+=8000;tot+=8000;}
		if(w[i].f>85&&w[i].c>80) {w[i].ans+=4000;tot+=4000;}
		if(w[i].f>90) {w[i].ans+=2000;tot+=2000;}
		if(w[i].f>85&&w[i].xi=='Y') {w[i].ans+=1000;tot+=1000;}
		if(w[i].c>80&&w[i].gb=='Y')	{w[i].ans+=850;tot+=850;}
	}
	int mmax = -1,p = -1;
	for(int i = 0;i<n;++i){
	if(w[i].ans>mmax)	{mmax=w[i].ans; p= i;}
		
	}
	cout<<w[p].a<<endl<<w[p].ans<<endl;
	cout<<tot<<endl;
return 0;	
}
