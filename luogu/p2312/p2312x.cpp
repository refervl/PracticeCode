#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int p=1000000007;//ȡģ�ȽϷ���qwqΪ�˳�����ֵĴ������ģ�������� 
bool t=true;//�����ж��Ƿ��н� 
int n,m,ans,cnt,sum=0;//cnt��¼��ĸ�����sum�����������ʽ�Ľ�� 
int A[103],key[1000003];
//A[]��¼ʽ�е�a0,a1,a2(ע������0Ϊ���)
//key��¼ÿ�����ֵ 
ll read()//�����Ż�(�ƺ����ӻ�T������w) 
{
    ll sum=0,fg=1;
    char c=getchar();
    while(c < '0' || c > '9')
    {
        if(c=='-') fg=-1;//��������������¼ 
        c=getchar();
    }
    while(c >='0' && c <='9')
    {
        sum=((sum*10)+c-'0')%p;
        //ע����ΪA[]���ܴܺ����Զ���ʱ��Ҫ����ȡģ���� 
        c=getchar();
    }
    return sum*fg;
    //����Ǹ���(fg==-1���������˸���)��ô���ص�ֵΪ���� 
}
void print(int x)//����Ż�(������Բ���qwq) 
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
    {
        print(x/10);
    }
    putchar(x%10+'0');
}
bool calc(ll x)
{
    sum=0;//һ��Ҫ���㣡����(��Ȼֻ��10��������) 
    for(ll i=n;i>=1;i--)
    {
        sum=((A[i]+sum)*x)%p;
        //���������ؾ����㷨�����ʽ��ֵ ע��A[0]������Ҫ��x��
    }
    sum=(sum+A[0])%p;//����������A[0]
    return !sum;//�������0˵��xֵΪ�ö���ʽ�Ľ⣬����1(true) 
}
int main()
{
	freopen("testdata(15).in","r",stdin);
    n=read();
    m=read();
    for(ll i=0;i<=n;i++)
    {
        A[i]=read();
    }
    for(ll i=1;i<=m;i++)
    {
        if(calc(i))//������ص���1(true)��˵���н� 
        { 
            t=false; 
            ans++;//��¼�𰸸��� 
            key[++cnt]=i;//��¼ÿ�����ֵ 
        }
    }
    if(t)
    {
        cout<<ans<<endl;//���tδ�ı���˵����ĸ���Ϊ0 
        return 0;
    }
    print(ans);
    printf("\n");
    for(ll i=1;i<=cnt;i++)
    {
        print(key[i]);
        printf("\n");
    }
    fclose(stdin);
    return 0;
}
