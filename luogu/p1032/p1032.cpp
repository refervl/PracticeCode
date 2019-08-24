#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>            
#include<map>
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
typedef pair<string,int> psi;
map<string,int> m;
queue<psi> q;
string s1[7],s2[7],s,e;int len;
int bfs(){
	
	m[s] = 1;
	q.push({s,0});
	while(!q.empty()){
		psi t = q.front();
		q.pop();
		if(t.second>10) return -1;
		if(t.first==e) return t.second;
		For(i,0,len){
			psi tt = t;
			while(true){
				int p = tt.first.find(s1[i]);
				
				if(p==-1) break;
				string st = t.first;
				st.replace(p,s1[i].size(),s2[i]);
				if(!m[st]){
					q.push({st,t.second+1});
					m[st] = 1;
				}
				tt.first[p] = '~';
			}
			
		}
	}
	return -1;
}
int main(){
	cin>>s>>e;

	
	while(cin>>s1[len]>>s2[len++]);
	len--;
	int ans = bfs();
	if(ans==-1) cout<<"NO ANSWER!"<<endl;
	else cout<<ans<<endl;
	return 0;
}

