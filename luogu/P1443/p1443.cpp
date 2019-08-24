#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

#define _for(i,a,b) for(int (i)= (a);i<(b);++i)
#define _rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
int v[405][405],map[405][405],n,m;
int way[9][3] = {{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}}; 
struct point{
	int x,y,step;
}P;
queue<point> q;
int main(){
	cin>>n>>m;
	int x1,y1;
	cin>>x1>>y1;
	INI(v);

	INI(map);
	P.x = y1;
	P.y = x1;
	P.step = 0;
	q.push(P);
	v[y1][x1] = 1;
	while(!q.empty()){
		point t = q.front();
		q.pop();
		
		_for(i,0,8){
			point xx;
			xx.x = t.x+way[i][0];
			xx.y = t.y+way[i][1];
			if(xx.x<=0||xx.x>m) continue;
			if(xx.y<=0||xx.y>n) continue;
			if(v[xx.x][xx.y]==1) continue;
		
			
			v[xx.x][xx.y]=1;
			xx.step = t.step+1;
			
			map[xx.x][xx.y] = xx.step;
			q.push(xx);
		}
	}
	_rep(j,1,n){
		 _rep(i,1,m){if(map[i][j]==0&&(i!=y1||j!=x1)) printf("%-5d",-1);else printf("%-5d",map[i][j]);}
		cout<<endl;
	}
	
return 0;	
} 

