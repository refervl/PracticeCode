#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> a[200005];
queue<int> q;
int v1[200005],v2[200005],ans[200005];
int main(){
	int n,m,t1,t2,s,e;
	cin>>n>>m;
	for(int i = 0;i<m;++i){
		cin>>t1>>t2;
		if(t1==t2) continue;
		a[t2].push_back(t1);
	}
	cin>>s>>e;
	q.push(e);	memset(v1,0,sizeof(v1));
	v1[e]=1;

	memset(ans,0,sizeof(ans));
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int n = a[x].size();
		for(int i = 0;i<n;++i){
			if(!v1[a[x][i]]){
			 v1[a[x][i]] = 1;
			 q.push(a[x][i]);
			}
		}
	}
	
	for(int i = 1;i<=n;++i) v2[i] = v1[i];
	
	for(int i = 1;i<=n;++i){
		
		if(!v1[i]){
			cout<<i<<endl;
			int n1 = a[i].size();
			for(int j = 0;j<n1;++j)
				v2[a[i][j]] = 0;
		}
	}

	q.push(e);
	while(!q.empty()){
	
		int x =q.front();
		q.pop();
		int n = a[x].size();
		for(int i = 0;i<n;++i){
			if(v2[a[x][i]]){
				v2[a[x][i]] = 0;
				q.push(a[x][i]);
				ans[a[x][i]] = ans[x]+1;
			}
		}
	}

	if(ans[s]==0) cout<<-1<<endl;
	else cout<<ans[s]<<endl;
	
	
return 0;	
}
