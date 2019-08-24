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
string s1,s2;
void solve(string z,string h){
    if(z.size()>0){
    char ch = h[h.size()-1];
    cout<<ch;
    int p = z.find(ch),e = z.size();
    solve(z.substr(0,p),h.substr(0,p));
    solve(z.substr(p+1),h.substr(p,e-1-p));
    }

}
int main(){
	cin>>s1>>s2;
    solve(s1,s2);
	return 0;
}