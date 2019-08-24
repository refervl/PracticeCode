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
typedef pair<int,int> pii;
int n,k;
pii a[10003];
int b[10003],f[10003];
int main(){
    int n,k;
    cin>>n>>k;
    For(i,0,k) {cin>>a[i].first>>a[i].second;b[a[i].first]++;}
    sort(a,a+k);
    int p = k-1;
    for(int i = n;i>=1;i--){
        if(b[i]==0) f[i] = f[i+1]+1;
        else{
            For(j,0,b[i]){
                if(f[i+a[p].second]>f[i]) f[i] = f[i+a[p].second];
                p--;
            }
        }
    }
    cout<<f[1]<<endl;
	return 0;
}