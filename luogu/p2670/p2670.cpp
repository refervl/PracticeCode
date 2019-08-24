#include<iostream>
using namespace std;
char a[105][105];
int c[105][105];
int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]=='*') c[i][j] = -1;
		}
	
	for(int i = 0;i<n;i++)
		for(int j =0;j<m;j++){
		if(a[i][j]=='*'){
			if((j+1<m)&&(a[i][j+1]=='?')) ++c[i][j+1];
			if((i+1<n)&&(a[i+1][j]=='?')) ++c[i+1][j];
			if((j-1>=0)&&(a[i][j-1]=='?')) ++c[i][j-1];
			if((i-1>=0)&&(a[i-1][j]=='?')) ++c[i-1][j];
			if((j+1<m)&&(i+1<n)&&(a[i+1][j+1]=='?')) ++c[i+1][j+1];
			if((j-1>=0)&&(i+1<n)&&(a[i+1][j-1]=='?')) ++c[i+1][j-1];
			if((j+1<m)&&(i-1>=0)&&(a[j+1][i-1]=='?')) ++c[i-1][j+1];
			if((j-1>=0)&&(i-1>=0)&&(a[i-1][j-1]=='?')) ++c[i-1][j-1];
		}
			
		}
		for(int i = 0;i<n;++i){
			for(int j = 0;j<m;++j)
				c[i][j]==-1 ? cout<<'*':cout<<c[i][j];
			cout<<endl;
		}
return 0;	
}
