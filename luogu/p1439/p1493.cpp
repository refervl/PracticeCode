#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF = 100005;
int a[INF],b[INF],c[INF],g[INF];
int main(){
	int n;
	freopen("10.in","r",stdin); 
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		c[a[i]] = i;
	}
	
	for(int i = 0;i<n;i++) cin>>b[i];
	for(int i = 1;i<=n;i++) g[i]  = INF;
	int m = 0;
	for(int i = 0;i<n;i++){
		int k = lower_bound(g+1,g+n+1,c[b[i]])-g;
		g[k] = c[b[i]];
		m = max(m,k);	
	}
	cout<<m<<endl;
	fclose(stdin);
return 0;	
}
