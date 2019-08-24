#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define _for(i,a,b) for(int i = (a);i<(b);++i)
#define _rep(i,a,b) for(int i = (a);i<=(b);++i)
#define LL long long
#define INI(x) memset(x,0,sizeof(x))

int main(){
	int n,ans;
	cin>>n;
	for(int i=1,j;i<=n;i=j+1){
        j=n/(n/i);
        ans+=(n/i)*(j-i+1);
    }
    
    cout<<ans<<endl;
    return 0;
} 

