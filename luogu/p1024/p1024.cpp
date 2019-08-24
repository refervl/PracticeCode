#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

double a,b,c,d;

int main(){

	
	cin>>a>>b>>c>>d;
	double i;
	for( i = -100;i<=100;i+=0.001){
	double x = i+0.001;
	if((a*i*i*i+b*i*i+c*i+d)*(a*x*x*x+b*x*x+c*x+d)<0)
		printf("%.2lf ",(x+i)/2.0);
		
		
	}
	cout<<endl;
return 0;	
}
