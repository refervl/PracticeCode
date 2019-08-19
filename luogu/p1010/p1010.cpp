#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>            
#include<stack>
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

string solve(int x){
    if(x==0) return "0";
    string s = "";
    string t = "";
    int i = 0;
    while(x){
        if(x&1){
            if(i==1) t+="2";
            else {
              
                t+="2(";
                t+=solve(i);
                t+=")";
            }
            if(s=="") t+="";
            else t+="+";
            s = t+s;
        }
        t = "";
        i++;
        x>>=1;
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;

	return 0;
}

