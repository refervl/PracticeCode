#include<iostream>
#include<cmath>
using namespace std;
double l1,lx1=0,lx2=0,v1,v2,t;
inline int d(double l){
	double ll = (l-l/v2*v1)/(v1+v2)*v1+l+l/v2*v1;
	if(ll>l1)
		return 1;
	else return 0;	
	
}
int main(){
	
	cin>>l1>>v1>>v2;

	lx1 = 0;
	lx2 = l1;
	while(fabs(lx1-lx2)>0.000001){	
	
		
		if(d(lx1+(lx2-lx1)/2.0)) lx2 = lx1+(lx2-lx1)/2.0;
		else lx1 = lx1 + (lx2-lx1)/2.0; 	
	}
	
	
	printf("%.06lf\n",lx1/v2+(l1-lx2)/v1);
	
	
return 0;	
}
