#include<iostream>
#include<algorithm>
using namespace std;
struct job{
	int t;
	int e;	
	int s;
}a[10000005];
bool rule(job a,job b){
	return a.s<b.s; 	
	
}
int main(){
	freopen("testdata(8).in","r",stdin);
	//freopen("testdata(7).out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i<n;++i){
		cin>>a[i].t>>a[i].e;	
		a[i].s = a[i].e-a[i].t;
	}
	
	sort(a,a+n,rule);
	
	int left = 0;
	int ok = 1;
int p = a[0].s;
	cout<<a[0].s<<' '<<a[0].e<<endl; 
	for(int i = 1;i<n;++i){
		cout<<a[i].s<<' '<<a[i].e<<' '<<left<<endl;
		if(a[i].s<a[i-1].e){
			if(left+p<a[i-1].e-a[i].s){
				ok = 0;
				cout<<-1<<endl;
				break;
			}
			else {
				//cout<<a[0].s<<' '<<left<<endl;
				if(left<0) 	a[0].s+=a[i].s-a[i-1].e;
				else if(left<a[i-1].e-a[i].s)
					a[0].s+=left+a[i].s-a[i-1].e;
					left+=a[i].s-a[i-1].e;
				//a[i].e+=a[i].s-a[i-1].e;
			}
		}
		else left+=a[i].s-a[i-1].e;
	}
	cout<<left<<' '<<a[0].s<<endl;
	if(ok){if(left<0)
		cout<<left+a[0].s<<endl;
		else cout<<a[0].s<<endl;
		
}
fclose(stdin);
//fclose(stdout);
return 0;	
}
