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
string s,d[8];
int sum[203][203],f[203][203];int p,k,n;
bool check(int l,int r){
    string st = s.substr(l,r-l+1);
    For(i,0,n) if(st.find(d[i])==0) return true;
    return false;
}
int main(){
    
    string t;
    cin>>p>>k;
    s+='0';
    while(p--){
        cin>>t;
        s+=t;
    }
        
    cin>>n;
    For(i,0,n) cin>>d[i];
    int len = s.length();
    
    for(int j = 1;j<=len-1;j++){
        for(int i = 1;i<=j;j++){
            if(check(i,j)) sum[i][j] = sum[i][j-1]+1;
            else sum[i][j] = sum[i-1][j];
        }
    }
    
    rep(i,1,k) f[i][i] = f[i-1][i-1]+sum[i][i];
    rep(i,1,len-1) f[i][1] = sum[1][i];
    rep(i,1,len-1)
        for(int j = 1;j<=k&&j<i;j++)
            For(l,j,i)
            f[i][j] = max(f[i][j],f[l][j-1]+sum[l+1][i]);
    cout<<f[len-1][k]<<endl;

	return 0;
}