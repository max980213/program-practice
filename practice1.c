/*
题目描述
你的任务是计算若干整数的和。
输入
输入的第一行为一个整数N，接下来N行每行先输入一个整数M，然后在同一行内输入M个整数。

输出
对于每组输入，输出M个数的和，每组输出之间输出一个空行。
样例输入
3
4 1 2 3 4
5 1 2 3 4 5
3 1 2 3
样例输出
10

15

6
*/

#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);

    int array[N];
    for(int i = 0;i < N;i++)
    {
        int M,flag = 0 , temp = 0;
        scanf("%d",&M);
        for(int j = 0;j < M;j++)
        {
            scanf("%d",&temp);
            flag = flag + temp;
        }
        array[i] = flag;
    }
    for(int i = 0;i<N;i++)
    {
        printf("%d\n\n",array[i]);
    }
    return 0;
}
