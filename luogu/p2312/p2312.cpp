#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define _for(i,a,b) for(int (i)= (a);i<(b);++i)
#define _rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
#define mod 1000000007
LL a[1000005],c1[1000005];
inline LL read(){
	LL ans = 0,f = 1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f = -1; c=getchar();}
	while(c>='0'&&c<='9'){ans = (ans*10+c-'0')%mod;c = getchar();}
	
	return ans*f;

}
int main(){
	freopen("testdata(15).in","r",stdin);
	int n,m;
	cin>>n>>m;
	LL count=0;
	
	_rep(i,0,n)
		{a[i] = read();}
	
	LL ans = 0;
	
	_rep(i,1,m){
		ans = 0;
		
		for(int j = n;j>=1;j--)
			ans = ((a[j]+ans)*i) % mod;
			 
		ans = (ans+a[0])%mod;
		
		if(ans ==0){
			count++;
			c1[count] = i;	
		}
	}
		cout<<count<<endl;
	_rep(i,1,count)
		cout<<c1[i]<<endl;
		fclose(stdin);
return 0;	
} 

