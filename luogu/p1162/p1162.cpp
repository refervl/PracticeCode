#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define _for(i,a,b) for(int (i) = (a);i<(b);++i)
#define _rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
int way[5][3] = {{1,0},{-1,0},{0,-1},{0,1}},map[32][32];
int v[32][32],c[1000];
int n,p=1;
void dfs(int x,int y){
		v[x][y] = 1;
		map[x][y] = p;
		if(x==n-1||x==0||y==n-1||y==0)
			c[p]=0;
		_for(i,0,4){
			if(x+way[i][0]>=n||x+way[i][0]<0) continue;
			if(y+way[i][1]>=n||y+way[i][1]<0) continue;
			if(v[x+way[i][0]][y+way[i][1]]!=0) continue;
			if(map[x+way[i][0]][y+way[i][1]]==1) continue;
			dfs(x+way[i][0],y+way[i][1]);
		}
}
int main(){
	
	cin>>n;
	INI(v);
	INI(c); 
	c[1] = 1;
	_for(i,0,n)
		_for(j,0,n) cin>>map[i][j];
		
	_for(i,0,n)
		_for(j,0,n){
			if(!v[i][j]&&map[i][j]!=1){
				c[++p] = p;
				dfs(i,j);
			}
		}
		
		
		
	_for(i,0,n){
		_for(j,0,n){
			if(c[map[i][j]]==0) cout<<0<<' ';
			else if(c[map[i][j]]>2) cout<<2<<' ';
			else cout<<map[i][j]<<' ';
		}
		cout<<endl;
	}
return 0;	
} 

