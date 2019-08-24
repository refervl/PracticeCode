#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
    int start;   //��ʼʱ�� 
    int comes;   //������ʲôʱ����� 
};
struct node que[1000001];
int n;
bool check(int cnt)
{
    int x,y,tnt=cnt;
    for(x=1;x<=n;x++)
    {
        if(que[x].start+tnt<=que[x].comes)//�����ǰ��ʱ��������������ʱ��С�ڵ��ڽ���ʱ�䣬���µ�ʱ����ھɵ�ʱ���������ʱ��
            tnt=que[x].start+tnt;
        else
            return false;//����˵����������Ϸ�
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
        scanf("%d %d",&que[i].start,&que[i].comes);//��������
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(que[i].comes>que[j].comes)
                swap(que[i],que[j]);//����ʱ��̵������ǰ�洦��
    while(left<=right)//���ֻ��һ��ģ�壬����ʹ�õ��Ǽ�¼�𰸷�
    {
        mid=(left+right+1)/2;//��ֹ��ѭ��
        if(check(mid))
        {
            ans=mid;    //���������Ϸ�����ô�������ұ�Ѱ�Ҹ��Ž�
            left=mid+1;
        }
        else
            right=mid-1;//���򣬾����������Ѱ�ҽ�
    }
    if(ans!=0)
        cout<<ans;
    else
        cout<<-1;
        fclose(stdin);
    return 0;//Բ������
}
