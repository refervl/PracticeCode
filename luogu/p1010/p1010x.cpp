#include<bits/stdc++.h>
using namespace std;
int x,sum;
int cf(int a,int b){//由于cmath的pow在这里不好用，就手写了一个计算乘方的函数。
    int z=1; 
    for(int i=0;i<b;i++){
        z*=a;
    }
    return z; 
}
void digui(int n){//进行递归的核心模块
    int y;
    if(n==0) return;//递归终止条件
    for(int i=0;i<=15;i++){//这个是用来找到比n小的2次方中最大的
        y=i;//进行储存
        if(cf(2,i)>n){//当2次方第一次大于n时
            y--;//变为小于n
            break;//跳出循环
        }
    }
    if(y==0) cout<<"2(0)";//输出2的0次方
    if(y==1) cout<<"2";//同理，输出2的1次方
    if(y>1){//当次方大于一时
        cout<<"2(";//添加2
        digui(y);
        cout<<")";//结尾必须的补括号
    }
    if(n!=cf(2,y)){//当n不等于2的y次方时
        cout<<"+";//添加号
        digui(n-cf(2,y)); //递归剩余的
    } 
}          
int main(){
    cin>>x;
    digui(x);
    return 0;
}//表抄代码，本蒟蒻只是希望能给奋斗于此题的同学一些思路。