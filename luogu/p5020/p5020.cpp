#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))

int a[103],v[2500003];

int main(){
	freopen("testdata(29).in","r",stdin);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		INI(v);
		INI(a);
		
		cin>>n;
		For(i,0,n) {cin>>a[i];v[a[i]] = -1;}
		sort(a,a+n);
		
		
		
		For(i,0,n){
			if(v[a[i]]==-1) ans++;
			if(abs(v[a[i]])==1){
			For(k,0,n)
			{	For(
				v[i] = 1;
				v[i+a[k]] = 1;
			}
		}
		}
		For(i,0,n){
			if(v[a[i]]==-1) ans++; 
		}
		cout<<ans<<endl;
		
			
	}
	 fclose(stdin);
	return 0;	
} 

