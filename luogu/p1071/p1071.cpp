#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char c1[1000],c2[1000],c3[1000],v[30];
	int n[1000];
	memset(n,0,sizeof(n));
	memset(v,0,sizeof(v));
	cin>>c1>>c2>>c3;
	
	int n1 = strlen(c1);
	if(n1<26) {cout<<"Failed"<<endl;return 0;}
	
	for(int i = 0;i<n1;++i){
		int t = c1[i]-'A'+1;
		
		if((n[t]!=0&&(n[t]!=c2[i]-'A'+1))||(v[c2[i]-'A'+1]!=0&&v[c2[i]-'A'+1]!=t)) {cout<<"Failed"<<endl;return 0;}
		
		n[t] = c2[i]-'A'+1;
		v[c2[i]-'A'+1]=t;
	}
	for(int i = 1;i<=26;++i)
		if(n[i]==0) {cout<<"Failed"<<endl;
					return 0;
				}
				
	int n2 = strlen(c3);
	
	for(int i = 0;i<n2;++i){
		
		int t = c3[i]-'A'+1;
		
		cout<<(char)(n[t]+64);
	}
	cout<<endl;
return 0;	
}
