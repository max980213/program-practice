//贪心算法实例
//问题描述：给定月饼种类数量，和所有种类月饼的库存量、总售价以及市场的最大需求量，计算最大收益
//思路：采用”总是选择单价最高的月饼出售“策略

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>  //sort()函数在该头文件里

using namespace std;

struct mooncake
{
    double store; //库存量
    double sell;  //总售价
    double price; //单价
}cake[1010];

bool cmp(mooncake a,mooncake b)
{
    return a.price>b.price;    //将月饼按照从高到低的顺序排序
}

int main()
{
    int n;
    double D;
    scanf("%d %lf",&n,&D);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&cake[i].store);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&cake[i].sell);
        cake[i].price=cake[i].sell/cake[i].store;   //计算单价
    }
    sort(&cake[0],&cake[n],cmp);     //需要记住sort()函数对数组进行排序，传入的参数为地址
    double ans=0;   //计算收益
    for(int i=0;i<n;i++)
    {
        if(cake[i].store<=D)  //如果需求量大于该种月饼库存量
        {
            D-=cake[i].store;
            ans+=cake[i].price*cake[i].store;    //该种月饼全部卖出
        }
        else
        {
            ans+=cake[i].price*D;    //如果需求量小于库存量
            break;                   //则按照需求量全部卖出
        }
    }
    printf("%.2f\n",ans);
    return 1;
}
