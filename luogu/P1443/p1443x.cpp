#include <cstdio>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;
struct xy{
    int x,y;
}node,Top;
const int dx[4]={1,-1,2,-2};
const int dy[4]={1,-1,2,-2};//虽说一共16个方向 但是在程序中有具体判断
int a[401][401];
bool b[401][401];
int n,m;
void bfs(int x,int y,int step){
    a[x][y] = step;
    b[x][y] = false;
    queue<xy> Q;//构建队列
    node.x = x;
    node.y = y;
    Q.push(node);//起始点入队
    while (!Q.empty()){
        Top=Q.front();//取出队首点
        Q.pop();//队首点出队
            for (int i=0;i<4;i++)
                for (int j=0;j<4;j++)
                    if (abs(dx[i])!=abs(dy[j])){//判断方向
                        int NewX=Top.x+dx[i];
                        int NewY=Top.y+dy[j];
                        if (NewX<1||NewX>n||NewY<1||NewY>m) continue;//判断越界
                        if (b[NewX][NewY]){//使用布尔数组保证每个点只入队一次 时间复杂度明显低于DFS
                            node.x=NewX;
                            node.y=NewY;
                            Q.push(node);
                            b[NewX][NewY] = false;//标记已入队
                            a[NewX][NewY] = a[Top.x][Top.y]+1;//路径+1
                        }
                    }
    }
}
int main(){
    memset(b,true,sizeof(b));
    memset(a,-1,sizeof(a));
    int x,y;
    scanf("%d%d%d%d" ,&n ,&m ,&x ,&y );
    bfs(x,y,0);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)
            printf("%-5d", a[i][j]);//注意场宽 我在这被卡了两次= =
        printf("\n");
    }
    return 0;
}
