#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int start;   //起始时间 
    int comes;   //必须在什么时间结束 
};
struct node que[1000001];
int n;
bool check(int cnt)
{
    int x,y,tnt=cnt;
    for(x=1;x<=n;x++)
    {
        if(que[x].start+tnt<=que[x].comes)//如果当前的时间加上任务所需的时间小于等于结束时间，将新的时间等于旧的时间加上任务时间
            tnt=que[x].start+tnt;
        else
            return false;//否则，说明这个数不合法
    }
    return true;
}
int main()
{
	freopen("testdata(8).in","r",stdin);
    int right=1000000000,left=1,mid=(left+right)/2;
    int i,j,k,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d %d",&que[i].start,&que[i].comes);//读入数据
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(que[i].comes>que[j].comes)
                swap(que[i],que[j]);//结束时间短的需放在前面处理
    while(left<=right)//这个只是一个模板，本人使用的是记录答案法
    {
        mid=(left+right+1)/2;//防止死循环
        if(check(mid))
        {
            ans=mid;    //如果这个数合法，那么在它的右边寻找更优解
            left=mid+1;
        }
        else
            right=mid-1;//否则，就在它的左边寻找解
    }
    if(ans!=0)
        cout<<ans;
    else
        cout<<-1;
        fclose(stdin);
    return 0;//圆满结束
}
