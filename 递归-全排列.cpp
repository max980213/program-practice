#include <stdio.h>

#define MAX 11

int n,p[MAX],hashtable[MAX]={false};   //p是当前排列  hashtable用于记录整数x是否在p中

void generateP(int index)    //当前处理排列的第index位
{
    if(index==n+1)
    {
        for(int i=1;i<=n;i++)     //递归边界，输出排列
            printf("%d",p[i]);
        printf("\n");
        return;
    }
    for(int x=1;x<=n;x++)     //枚举1~n，并试图将x插入
    {
        if(hashtable[x]==false)   //如果x不在p中，则放入
        {
            p[index]=x;           //记x已在p中
            hashtable[x]=true;    
            generateP(index+1);   //处理第index+!位
            hashtable[x]=false;   已处理完p[index]为x的子问题，还原状态
        }
    }
}

int main()
{
    n=4;
    generateP(1);
    return 0;
}




