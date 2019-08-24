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
int n;
vector<int> v[30];
void dfs(int fa){
    cout<<(char)(fa+'a');
    if(v[fa][0]==-1&&v[fa][1]==-1) return;
    if(v[fa][0]!=-1) dfs(v[fa][0]);
    if(v[fa][1]!=-1) dfs(v[fa][1]);
}
int main(){
	int n;
    cin>>n;
    int head;
    For(i,0,n){
        char a,b,c;
        cin>>a>>b>>c;
        if(i==0) head = a-'a';
        b=b=='*'?-1:b-'a';
        c=c=='*'?-1:c-'a';
        v[a-'a'].pb(b);
        v[a-'a'].pb(c);
    }
    dfs(head);
	return 0;
}