//n皇后问题
//n*n的棋盘，放置n个棋子，不允许同行列同对角线
//为减少计算量，转化为全排列问题

#include <stdio.h>
#include <stdlib.h>   //abs()函数在这个头文件里
#define MAX 25

int n,p[MAX],hashtable[MAX];
int num=0;
void generateP(int index,int n);

int main()
{
    printf("请输入n：\n");
    scanf("%d",&n);
    generateP(1,n);
    printf("%d", num);
    return 0;
}

void generateP(int index,int n)
{
    //bool flag=true;
    if(index==n+1)
    {
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(abs(i-j)==abs(p[i]-p[j]))
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            num++;
    }
    else
    {
        for(int x=1;x<=n;x++)
        {
            if(hashtable[x]==false)
            {
                p[index]=x;
                hashtable[x]=true;
                generateP(index+1,n);
                hashtable[x]=false;
            }
        }
    }
}

