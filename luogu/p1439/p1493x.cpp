# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
int a[100005],t[100005],A[100005],B[100005],f[100005];
bool cmp(int a,int b)
{
    return a<b;
}
int solve(int l,int r,int x)
{
    int mid=(l+r)/2;;
    if (l==r) return l; 
    if (a[mid]>x) return solve(l,mid,x);
    if (a[mid]<=x) return solve(mid+1,r,x);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&A[i]);
    for (int i=1;i<=n;i++) scanf("%d",&B[i]);
    for (int i=1;i<=n;i++) f[A[i]]=i;
    for (int i=1;i<=n;i++) t[i]=f[B[i]];
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
        if ((i==0)||(t[i]>a[a[0]])) a[++a[0]]=t[i];
        else if (t[i]<a[a[0]]) a[solve(1,a[0],t[i])]=t[i];
//a[lower_bound(a+1,a+a[0]+1,t[i])-a]=t[i];(替换a[solve(1,a[0],t[i])]=t[i];也行但是会稍微慢一点。。)
    }
    printf("%d\n",a[0]); 
    return 0;
}
