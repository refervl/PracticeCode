#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>             
using namespace std;

#define For(i,a,b) for(int (i)= (a);i<(b);++i)
#define rep(i,a,b) for(int (i) = (a);i<=(b);++i)
#define ll long long
#define INI(x) memset(x,0,sizeof(x))
#define MAXN 10003
struct Kruskal{
    struct edge{int u,v,cost;};
    bool rule(edge a,edge b){
        return a.cost<b.cost;
    }
    edge es[MAXN];int pp = 0;
    int p[MAXN],rank[MAXN];
    
    void Addedge(int u,int v,int cost){
        es[pp].u = u;
        es[pp].v = v;
        es[pp++].cost = cost;
    }
    void init(int n){
        For(i,0,n){
            p[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if(p[x]==x){
            return x;
        }else {
            return p[x] = find(p[x]);
        }
    }
    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x==y) return;

        if(rank[x]<rank[y]){
            p[x] = y;
        }else{
            p[y] = x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }
    bool same(int x,int y){
        return find(x)==find(y);
    } 
    int V,E;
    void Add(int v){
        E = pp;
        V = v;
    } 
    int ans = 0;
    void kruskal(){
        sort(es,es+E);
        init(V);
        For(i,0,E){
            edge e = es[i];
            if(!same(e.u,e.v)){
                unite(e.u,e.v);
                ans+=e.cost;
            }
        }
    }
};
Kruskal res;
int main(){
    int n,t;
    cin>>n;
    For(i,0,n)
        For(j,0,n){
            cin>>t;
            if(i<j){
                res.Addedge(i,j,t);
            }
        }
    res.Add(n);
    res.kruskal();
    cout<<res.ans<<endl;

	return 0;	
} 

