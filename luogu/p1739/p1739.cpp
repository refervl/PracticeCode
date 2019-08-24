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
string s;
stack<int> res;
int main(){
	cin>>s;
    int len = s.length();
    For(i,0,len){
        if(s[i]=='(') res.push(1);
        else if(s[i]==')'){
            if(res.empty()) {
                cout<<"NO"<<endl;
                return 0;
            }
            res.pop();
        }
    }
    if(res.empty()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0;
}