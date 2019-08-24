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

struct p{
	int x,y,f,c;
};
queue<p> q;
int map[55][55],v[55][55][4]; 
int way[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	INI(map);
	INI(v);
	int n,m,t;
	cin>>n>>m;
	rep(i,1,n)
		rep(j,1,m){cin>>t;
	
		if(t==1){
		map[i-1][j]=1;
		map[i-1][j-1]=1;
		map[i][j]=1;
		map[i][j-1] = 1;	
		}
		}
	
	
	int sx,sy,ex,ey;
	char c;
	cin>>sx>>sy>>ex>>ey>>c;
	p pp;
	pp.x = sx;pp.y = sy;pp.c = 0;
	if(c=='E') pp.f = 0;
	else if(c=='S') pp.f = 1;
	else if(c=='W') pp.f = 2;
	else if(c=='N') pp.f = 3;
	q.push(pp);
	while(!q.empty()){
		 
		p tt = q.front();
		q.pop();
		
		if(v[tt.x][tt.y][tt.f]==1) continue;
		v[tt.x][tt.y][tt.f] = 1;
		if(tt.x==ex&&tt.y==ey){
			cout<<tt.c<<endl;
			return 0;
		}
		
	
		p tx = tt;
		tx.f = (tt.f -1+4) %4;
		tx.c = tt.c+1;
		q.push(tx);
		tx.f = (tt.f+1+4) %4;
		q.push(tx);
		tx.f = tt.f;
		rep(i,1,3){
			tx.x = tt.x;tx.y = tt.y;
		 	tx.x+=way[tx.f][0]*i;
		 	tx.y+=way[tx.f][1]*i;
		 
		 	if(tx.x<=0||tx.x>=n) continue;
		 	if(tx.y<=0||tx.y>=m) continue;
		 	if(map[tx.x][tx.y] ==1) break;
		 	if(v[tx.x][tx.y][tx.f]==1) continue;
				
		 	q.push(tx);
		}
	}
	cout<<-1<<endl;
return 0;	
} 

