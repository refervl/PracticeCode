#include<iostream>
#include<algorithm>
using namespace std;
int e[12];
struct p{
	int num,d,numm;
} w[20005];
bool rule(p a,p b){
	
	return a.num>b.num;	
}
bool rule2(p a,p b){
	if(a.num==b.num)
		return a.numm<b.numm;
		else return a.num>b.num;	
}
int main(){
	//freopen("testdata(10).in","r",stdin);
	
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=10;++i)
		cin>>e[i];
		
	for(int i = 1;i<=n;++i){
		cin>>w[i].num;
		w[i].numm = i;
	}
		
	sort(w+1,w+1+n,rule2);
	for(int i = 1;i<=n;++i){
		w[i].d = i;
		w[i].num+=e[(w[i].d-1)%10+1];	
	}
	sort(w+1,w+n+1,rule2);
	for(int i = 1;i<=k;++i)
		cout<<w[i].numm<<' ';
		cout<<endl;
		
		//fclose(stdin);
return 0;	
}
