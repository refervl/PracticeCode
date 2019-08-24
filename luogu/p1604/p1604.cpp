#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define _for(i,a,b) for(int (i)= (a);i<(b);++i)
#define _rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
char a[2005],b[2005];
int a1[2005],b1[2005],ans[2005];
char s[]{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int main(){
	int n;
	cin>>n;
	cin>>a>>b;
	int n1 = strlen(a);
	int n2 = strlen(b);
	INI(a1);
	INI(b1); 
	INI(ans);

	_for(i,0,n1) {
		if(a[i]>='0'&&a[i]<='9') a1[n1-1-i] = a[i]-'0';
		else a1[n1-1-i] = a[i]-'A'+10;
	}
	_for(i,0,n2){
		if(b[i]>='0'&&b[i]<='9') b1[n2-1-i] = b[i]-'0';
		else b1[n2-1-i] = b[i]-'A'+10;
	}
	
	int mm = max(n1,n2);
	_for(i,0,mm){
	
		ans[i]+=a1[i]+b1[i];
		if(ans[i]>=n){
			ans[i]%=n;
			ans[i+1]++;
		}
	}
	int f = 1;
	for(int i = 2002;i>=0;i--){
		if(ans[i]==0&&f==1) continue;
		else {f = 0;
			cout<<s[ans[i]];
		}
	}
	cout<<endl;
return 0;	
} 

