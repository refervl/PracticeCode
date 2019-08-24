#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))

struct node{
    int x1,x2,l;
}a[6000];
int p[6000];
bool rule(node a,node b){
    return a.l<b.l;	
}
int find(int x){
    return p[x] == x?x:find(p[x]);
   
}

int main(){
	freopen("testdata(25).in","r",stdin);
    int n,t;
    cin>>n;
    int tot = 0;
    rep(i,1,n) p[i] = i;
    rep(i,1,n)
        rep(j,1,n){
                cin>>t;
                if(i>j){
                    a[++tot].x1 = i;
                    a[tot].x2 = j;
                    a[tot].l = t;
                }
        }
    
    sort(a+1,a+tot+1,rule);
    int ans = 0,c = 1;
    rep(i,1,tot){
        int x = find(a[i].x1),y = find(a[i].x2);
        if(x!=y){ ans+=a[i].l;p[x] = a[i].x2;c++;if(c==n) break;}
        
    }	
        cout<<ans<<endl;
        fclose(stdin);
    return 0;	
} 
