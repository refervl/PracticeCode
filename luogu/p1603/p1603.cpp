#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char dic[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};
int di[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
int main(){
	char a[30];
	int num[10];
	int p=0;
	for(int i = 0;i<6;++i){
		cin>>a;
		for(int j = 0;j<=26;++j){
				if(!strcmp(a,dic[j])){
					num[++p]=di[j];
					break;	
				}
		}
	}
	
	sort(num+1,num+p+1);
	int f = 1;
	
	for(int i = 1;i<=p;++i){
		if(!f){
			
			printf("%.2d",num[i]);
		}
		else {if(num[i]!=0){ printf("%d",num[i]);f=0;}}
}
	if(!f) printf("\n");
	if(f) printf("0\n");
return 0;
} 
