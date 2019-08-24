#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int p[20]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51};
long long maxn=-1,num=-1;
void get(long long m,int f,int t,int pr)
{//f为当前质数的编号 ,当前指数<pr
//t为当前约数的个数 
		cout<<num<<endl;
    if(t>maxn||(t==maxn&&m<num))
        num=m,maxn=t;
    int j=0,nt;
    long long i=m;
    while(j<pr)
    {
        j++;
        if(n/i<p[f])break;
        nt=t*(j+1);
        i=i*p[f];
        if(i<=n)    get(i,f+1,nt,j);
    }
}
int main()
{
    cin>>n;
    get(1,1,1,30);
    cout<<num;
}
