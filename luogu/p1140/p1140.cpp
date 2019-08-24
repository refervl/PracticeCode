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
int tab[5][5]=
{
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};
map<char,int> m;
string s1,s2;
int a[103],b[103],f[130][105];
int main(){
    m['A'] = 0;
    m['C'] = 1;
    m['G'] = 2;
    m['T'] = 3;
    int n1,n2;
    cin>>n1>>s1;
    cin>>n2>>s2;
    rep(i,1,n1) a[i] = m[s1[i-1]];
    rep(i,1,n2) b[i] = m[s2[i-1]];
    For(i,1,101) For(j,1,101) f[i][j] = -9999999;
    rep(i,1,n1) f[i][0]=f[i-1][0]+tab[a[i]][4];
    rep(i,1,n2) f[0][i]=f[0][i-1]+tab[b[i]][4];
    rep(i,1,n1)
        rep(j,1,n2){
            f[i][j] = max(f[i][j],f[i-1][j]+tab[a[i]][4]);
            f[i][j] = max(f[i][j],f[i][j-1]+tab[b[j]][4]);
            f[i][j] = max(f[i][j],f[i-1][j-1]+tab[a[i]][b[j]]);
        }
    
    cout<<f[n1][n2]<<endl;
	return 0;
}