#include<cstdio>
#include<algorithm>
using namespace std;
int e[12],n,k;
struct person{
    int w;//Ȩֵ 
    int num;//��� 
    int d;//��� 
}p[20010];//����ÿ���˵���Ϣ 
int w_comp(const person &a,const person &b){
    if(a.w!=b.w)return a.w>b.w;//�Ӵ�С���� 
    return a.num<b.num;//���С���� 
}//�ṹ������ 
int main(){
		freopen("testdata(10).in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=0;i<10;i++)scanf("%d",&e[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].w);
        p[i].num=i+1;
    }//����+��� 
    sort(p,p+n,w_comp);//��һ������ 
    for(int i=0;i<n;i++){
        p[i].d=i%10;//���� 
        p[i].w+=e[p[i].d];//����e[i] 
    }
    sort(p,p+n,w_comp);//�ڶ������� 
    for(int i=0;i<k;i++)printf("%d ",p[i].num);
    fclose(stdin);
}
