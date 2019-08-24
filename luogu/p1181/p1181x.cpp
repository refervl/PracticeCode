#include<cstdio>
using namespace std;
int a[100010] ;
int main()
{
    int n,m,i,j,k,ans=0,sum=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]+sum>m)
        {
            sum=0;
            ans++;
        }
        sum=sum+a[i];
    }
    if(sum)
    {
        ans++;
    }
    printf("%d",ans);
    return 0;
}
