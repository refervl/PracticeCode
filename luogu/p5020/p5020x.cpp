#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mon[25001]={};
/*
mon[i]=0 ��ʾi��ֵ��Ǯ���ܱ��ճ���
mon[i]=1 ��ʾi��ֵ��Ǯ���Ա��ճ���
mon[i]=2 ��ʾi��ֵ��Ǯ�ǻ���ϵͳ�б������е�Ǯ
*/
int coins[101]={};//��Ǯ����ֵ
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
        //�ѻ���ϵͳ�е�Ǯ���
        sort(coins+1,coins+1+n);
        for (int i=1;i<=coins[n];i++)
        {
            if (mon[i]>0)
            //���mon[i]�ܱ��ճ���
            //��ômon[i+coins[j]]Ҳ�ܱ��ճ���
            {
                for (int j=1;j<=n;j++)
                    if (i+coins[j]<=coins[n])
                    //��ֹ����Խ��
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
