#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,y=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='0')y=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*y;
}
int n,m;
vector<int>v[10005];
bool cando[10005],er[10005];
queue<int>q;
int st,ed;
int ans[10005];
int main()
{    
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int a=read(),b=read();
        if(a==b)continue;//ȥ���Ի�
        v[b].push_back(a);
    }
    st=read(),ed=read();
    cando[ed]=1;//��һ��bfs
    q.push(ed);
    while(!q.empty())
    {
        int no=q.front();
        q.pop();
        for(int i=0,j=v[no].size();i<j;i++)
            if(!cando[v[no][i]]){cando[v[no][i]]=1;q.push(v[no][i]);}//��Ǵ��յ���Ե���ĵ�
    }
    
    memcpy(er,cando,sizeof(cando));//׼���ڶ��α��
        //ע����������еڶ��������ǣ���һ��������ɾ���к�Ч�ͣ����һ���㿪ʼ����ǣ���ͨ��һ����ű���С�ĵ�ɾ���ˣ�
       //��ô���ʵ�����ʱ�򣬾ͻᱻ���ɿ�ʼ��û����ǵĵ㣬��ͨ�����ѺϷ���ɾ����
      //��������֮�󣬺Ϸ��㶼������ˡ�
    for(int i=1;i<=n;i++)
        if(!cando[i])
            for(int j=0,k=v[i].size();j<k;j++)
                if(er[v[i][j]])
                    er[v[i][j]]=0;
        //���һ��bfs�Ҵ𰸡�
        for(int i = 1;i<=n;i++) cout<<er[i]<<endl;
    q.push(ed);
    while(!q.empty())
    {
        int no=q.front();
        q.pop();
        for(int i=0,j=v[no].size();i<j;i++)
            if(er[v[no][i]])
            {
                q.push(v[no][i]);
                er[v[no][i]]=0;
                ans[v[no][i]]=ans[no]+1;
            }
    }
       //��ĿҪ�������
    if(ans[st]==0)printf("-1");
    else printf("%d",ans[st]);
    return 0;
}
