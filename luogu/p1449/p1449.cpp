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
stack<int> st;
int main(){
	cin>>s;
    int len = s.length();
    int a1,a2;
    For(i,0,len){
        int res = 0;
        while(s[i]>='0'&&s[i]<='9') {res = res*10+s[i]-'0';i++;}
        if(s[i]=='.') st.push(res);
        if(s[i]=='+'){a1 = st.top();st.pop();a2 = st.top();st.pop();st.push(a1+a2);}
        if(s[i]=='*'){a1 = st.top();st.pop();a2 = st.top();st.pop();st.push(a1*a2);}
        if(s[i]=='-'){a1 = st.top();st.pop();a2 = st.top();st.pop();st.push(a2-a1);}
        if(s[i]=='/'){a1 = st.top();st.pop();a2 = st.top();st.pop();st.push(a2/a1);}
    }
    cout<<st.top()<<endl;
	return 0;
}