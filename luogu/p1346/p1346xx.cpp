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
#define maxn 10000
const int INF = 1<<29;
int n,s,e;
struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d) {}
};
struct Dijkstra{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    int d[maxn];
    int p[maxn];

    void init(int n){
        this->n = n;
        For(i,0,n) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int dist){
        edges.push_back(Edge(from,to,dist));
        m = edges.size();
        G[from].push_back(m-1);
    }

    struct HeapNode{
        int d,u;
        bool operator <(const HeapNode & rhs) const{
            return d>rhs.d;
        }
    };
    void dijkstra(int s){
    	
        priority_queue<HeapNode> Q;
        For(i,0,n) d[i] = INF;
        d[s] = 0;
        INI(done);
        Q.push((HeapNode){0,s});
        while(!Q.empty()){ 
            
            HeapNode x = Q.top();
            Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;
            For(i,0,G[u].size()){
                Edge& e = edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist){
                    d[e.to] = d[u]+e.dist;
                    p[e.to] = G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
};
Dijkstra res;
int main(){
    cin>>n>>s>>e;
    int nn,t;
    res.init(n); 
    For(i,0,n){
        cin>>nn;
        For(j,0,nn){
            cin>>t;
            if(j==0) res.AddEdge(i,t,0);
            else res.AddEdge(i,t,1);
        }
    }
    For(i,1,n) res.AddEdge(i,i,0);

    res.dijkstra(s);
    if(res.d[e]==INF) cout<<-1<<endl;
    else cout<<res.d[e]<<endl;
    return 0;	
} 