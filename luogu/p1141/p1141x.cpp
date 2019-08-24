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
int v[1005][1005];
int main(){
    INI(map);
    
    int n,m;
    cin>>n>>m;
    _rep(i,1,n)
        _rep(j,1,n) cin>>map[i][j];
    
    _for(i,0,m){
        point P;
        cin>>P.x>>P.y;INI(v);
        int count = 0;	
        q.push(P);
        v[P.x][P.y]= 1;
        while(!q.empty()){
            point tt = q.front(),t1;
            q.pop();
            
            _for(i,0,4){
                int tx = map[tt.x][tt.y];
                if(map[tt.x+way[i][0]][tt.y+way[i][1]]==tx) continue;
                if(tt.x+way[i][0]>n||tt.x+way[i][0]<=0) continue;
                if(tt.y+way[i][1]>n||tt.y+way[i][1]<=0) continue;
                if(v[tt.x+way[i][0]][tt.y+way[i][1]]!=0) continue;
                t1.x = tt.x+way[i][0];t1.y = tt.y+way[i][1];
                count++;
                v[t1.x][t1.y]= 1;
                q.push(t1);
            }
        }
        cout<<count+1<<endl;
    }
return 0;	
} 
