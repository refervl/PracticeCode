#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

#define _for(i,a,b) for(int (i) = (a);i<(b);++i)
#define _rep(i,a,b) for(int (i)= (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))
struct point{
	int x,y;
};
queue<point> q;
int way[5][3] = {{1,0},{-1,0},{0,1},{0,-1}}; 
char map[1005][1005];
int v[1005][1005],ans[1005][1005],ans1[1000005];
int main(){
	INI(map);
	INI(ans);
	INI(ans1);
	int n,m;
	int p=1;
	scanf("%d%d",&n,&m);
	_rep(i,1,n)
		_rep(j,1,n) scanf("%c",&map[i][j]);
		_rep(i,1,n)
		_rep(j,1,n) printf("%c",map[i][j]);
	
	_for(i,0,m){int x1,y1;
			scanf("%d%d",&x1,&y1);
			if(ans[x1][y1]!=0) {printf("%d\n",ans1[ans[x1][y1]]+1);continue;}
		point P;
		P.x = x1;P.y = y1;
		int count = 0;	
		q.push(P);
		v[P.x][P.y]= 1;
		ans[P.x][P.y]=p;
		while(!q.empty()){
			point tt = q.front(),t1;
			q.pop();
			
			_for(i,0,4){
				
				if(map[tt.x+way[i][0]][tt.y+way[i][1]]==map[tt.x][tt.y]) continue;
				if(tt.x+way[i][0]>n||tt.x+way[i][0]<=0) continue;
				if(tt.y+way[i][1]>n||tt.y+way[i][1]<=0) continue;
				if(v[tt.x+way[i][0]][tt.y+way[i][1]]!=0) continue;
				t1.x = tt.x+way[i][0];t1.y = tt.y+way[i][1];
				count++;
				v[t1.x][t1.y]= 1;
				ans[t1.x][t1.y] = p;
				q.push(t1);
			}
		}
		ans1[p++] = count;
		printf("%d\n",count+1);
	}

return 0;	
} 

