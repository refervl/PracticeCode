#include<bits/stdc++.h>

using namespace std;

struct node{
    int x,y,w;
}a[200002];

int f[200002];

bool cmp(node xx,node yy){//�ṹ������
    return xx.w<yy.w;
}

int find(int x){
//���鼯˵���˾����Ҹ����Ĺ��̣�ͬһ�����ڵ㼴ͬһ������
    if(x==f[x]) return x;
    f[x]=find(f[x]);
    return f[x];
}

int main(){
	freopen("testdata(25).in","r",stdin);
    int n,k,m=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        f[i]=i;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&k);
            if(j>i){
            //����ʱ��һ���жϾͿ����ˣ�����Ҫ����ô��
                m++;
                a[m].x=i;a[m].y=j;a[m].w=k; 
            }   
        }
    }
    sort(a+1,a+m+1,cmp);//����
    int ans=0,p=1;
    for(int i=1;i<=m;i++){
        if(find(a[i].x)!=find(a[i].y)){
        //�������һ������
            ans+=a[i].w;
            f[find(a[i].x)]=a[i].y;
            //�ϲ������ڵ�
            p++;
            if(p==n) break; 
        }
    }
    cout<<ans;
    fclose(stdin);
    return 0;
}
