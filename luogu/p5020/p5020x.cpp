#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mon[25001]={};
/*
mon[i]=0 表示i面值的钱不能被凑出来
mon[i]=1 表示i面值的钱可以被凑出来
mon[i]=2 表示i面值的钱是货币系统中本来就有的钱
*/
int coins[101]={};//存钱的面值
int T,n,ans=0;
int main()
{
	freopen("testdata(29).in","r",stdin);
    scanf("%d ",&T);
    while (T--)
    {
        ans=0;
        memset(mon,0,sizeof(mon));
        memset(coins,0,sizeof(coins));
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&coins[i]);
            mon[coins[i]]=2;
        }
        //把货币系统中的钱标好
        sort(coins+1,coins+1+n);
        for (int i=1;i<=coins[n];i++)
        {
            if (mon[i]>0)
            //如果mon[i]能被凑出来
            //那么mon[i+coins[j]]也能被凑出来
            {
                for (int j=1;j<=n;j++)
                    if (i+coins[j]<=coins[n])
                    //防止数组越界
                        mon[i+coins[j]]=1;
                    else break; 
            }
        }
        for (int i=1;i<=coins[n];i++)
            if (mon[i]==2) ans++;
        printf("%d\n",ans);
    }
    fclose(stdin);
}
