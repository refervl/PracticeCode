#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>            
#include<stack>
#include<map>
#include<set>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define ll long long
#define INI(x) memset(x,0,sizeof(x))
#define R(x) scanf("%d",&x)
#define W(x) printf("%d\n",x)
#define Rll(x) scanf("%lld",&x)
#define Wll(x) printf("%lld\n",x)
#define pb push_back

 

typedef vector<int> VI; 
const int N = 90;
 
int n, m;
int g[N];
VI f[N][N];
VI p[N];
 
VI add(VI x, VI y)
{
    VI c;
    
    for (int i = 0, t = 0; i < x.size() || i < y.size() || t; i++)
    {
        if (i < x.size()) t += x[i];
        if (i < y.size()) t += y[i];
        c.push_back(t % 1000000);
        t /= 1000000;
    }
    return c;
}
 
VI mul(VI a, int b)
{
    VI C;
  
    ll t = 0;
    for (int i = 0; i < a.size() || t; i++)
    {
        if (i < a.size()) t += (ll) a[i] *b;
        C.push_back(t % 1000000);
        t /= 1000000;
    }
    return C;
}
 
VI mmax(VI a, VI b)
{
    if (a.size() != b.size())
    {
        if (a.size() > b.size()) return a;
        return b;
    }
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] > b[i]) return a;
        if (a[i] <b[i]) return b;
    }
    return a;
}

 
int main()
{
    cin>>n>>m;
 
    p[0] = { 1 };
    rep(i,1,m)p[i] = mul(p[i - 1], 2);
 
    VI res(1, 0);
    For(i,0,n)
    {
        rep(j,1,m) cin>>g[j];
       rep(len,1,m)
        rep(l,1,m-len+1)
        {
            int r = l + len - 1;
            if (l == r) f[l][r] = mul(p[m - len + 1], g[r]);
            else
            {
                auto left = add(mul(p[m - len + 1], g[l]), f[l + 1][r]);
                auto right = add(mul(p[m - len + 1], g[r]), f[l][r - 1]);
                f[l][r] = mmax(left, right);
            }
        }
        res = add(res,f[1][m]);
    }
 
    
    cout<<res.back();
    for (int i = res.size() - 2; i >= 0; i--) printf("%06d", res[i]);

    return 0;
}
