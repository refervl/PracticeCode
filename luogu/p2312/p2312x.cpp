#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int p=1000000007;//取模比较方便qwq为了出现奇怪的错误建议多模几个质数 
bool t=true;//用来判断是否有解 
int n,m,ans,cnt,sum=0;//cnt记录解的个数；sum用来计算多项式的结果 
int A[103],key[1000003];
//A[]记录式中的a0,a1,a2(注意是以0为起点)
//key记录每个解的值 
ll read()//读入优化(似乎不加会T两个点w) 
{
    ll sum=0,fg=1;
    char c=getchar();
    while(c < '0' || c > '9')
    {
        if(c=='-') fg=-1;//如果读到负号则记录 
        c=getchar();
    }
    while(c >='0' && c <='9')
    {
        sum=((sum*10)+c-'0')%p;
        //注意因为A[]可能很大，所以读入时就要进行取模操作 
        c=getchar();
    }
    return sum*fg;
    //如果是负数(fg==-1，即读到了负号)那么返回的值为负数 
}
void print(int x)//输出优化(这个可以不加qwq) 
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
    sum=0;//一定要清零！！！(不然只有10分呜呜呜) 
    for(ll i=n;i>=1;i--)
    {
        sum=((A[i]+sum)*x)%p;
        //这里套用秦九韶算法求多项式的值 注意A[0]并不需要乘x！
    }
    sum=(sum+A[0])%p;//这里再算上A[0]
    return !sum;//如果答案是0说明x值为该多项式的解，返回1(true) 
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
        if(calc(i))//如果返回的是1(true)则说明有解 
        { 
            t=false; 
            ans++;//记录答案个数 
            key[++cnt]=i;//记录每个解的值 
        }
    }
    if(t)
    {
        cout<<ans<<endl;//如果t未改变则说明解的个数为0 
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
