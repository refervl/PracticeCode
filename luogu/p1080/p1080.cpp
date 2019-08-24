#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int pl[20005],di[20005],ml[20005],ml1=1,di1=0,ans[20005],as=0;
struct ss{
	int l,r,k;	
	
} q[10005];
bool rule(ss a,ss b){
	return a.k<b.k;	
}
void multi(int a){
	memset(pl,0,sizeof(pl));
	
	for(int i = 1;i<=ml1;i++){
		ml[i]*=a;
		pl[i+1] += ml[i]/10;
		ml[i]=ml[i]%10;
	}
	for(int i = 1;i<=ml1+4;i++){
		ml[i]+=pl[i];
		if(ml[i]>=10){
		ml[i+1]+=ml[i]/10;
		ml[i]=ml[i]%10;}	
		if(ml[i]!=0)
		ml1 = max(ml1,i);
	}
	
}
void d(int a){
	memset(di,0,sizeof(di));
		di1=0;
	int x=0;
	for(int i = ml1;i>=1;i--){
		x*=10;
		x+=ml[i];
		di[i] = x/a;	
		if(di1==0&&di[i]!=0)
		di1=i;	
		x %=a;
		
	}
	
	
}
void _cmp(){
	if(as<di1){
		for(int i = di1;i>=1;i--)
			ans[i]=di[i];	
			as=di1;
			
	}
	if(as==di1){
		for(int i = as;i>=1;i--){
			if(ans[i]<di[i]){
				for(int i = di1;i>=1;i--){
					ans[i]=di[i];	
						
				}break;
			}
		}
	}
}
int main(){
	int n;
	memset(ml,0,sizeof(ml));
	ml[1]=1;
	freopen("testdata(1).in","r",stdin);
	cin>>n;
	
	for(int i = 0;i<=n;i++){
		cin>>q[i].l>>q[i].r;
		q[i].k = q[i].l*q[i].r;
	}
	sort(q+1,q+1+n,rule);
	for(int i = 0;i<=n-1;i++){
		multi(q[i].l);
		d(q[i+1].r);
		_cmp();
	}

	for(int i = as;i>=1;i--)
		cout<<ans[i];
		cout<<endl;
	fclose(stdin);
return 0;	
}
