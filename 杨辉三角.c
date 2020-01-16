/*
题目描述：杨辉三角
控制台输入行数N，输出对应行数的杨辉三角
/*

#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int array[N][N+1];
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<i+1;j++)
        {
            if(j==0||j==i) //数组下标从0开始
            {
                array[i][j]=1;
            }
            else
            {
                array[i][j]=array[i-1][j-1]+array[i-1][j];
            }
        }
    }
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<i+1;j++)
            printf("%d ",array[i][j]);
        printf("\n");
    }
}
