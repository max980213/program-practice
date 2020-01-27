//简单贪心算法实例2
//问题描述：给定0~9各若干个，可以任意顺序排列这些数字，但必须全部使用，使得到的数最小。要求：0不可以做首位
//思路：先从1~9中选择个数不为0的最小的数输出，然后从0~9输出数字，每个数字输出次数是其剩余个数
//输入格式：每一行给出10个非负整数，顺序表示0~9的个数，总个数不超过50，至少有一个非0数字

#include <cstdio>

int main()
{
    int count[10];    //记录0~9数字的个数
    for(int i=0;i<10;i++)
    {
        scanf("%d",&count[i]);
    }
    for(int i=1;i<10;i++)
    {
        if(count[i]>0)
        {
            printf("%d",i);
            count[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++)
    {
            for(int j=count[i];j>0;j--)
            {
                printf("%d",i);
            }
    }
    return 1;
}
