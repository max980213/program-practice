//随机选择算法
//考虑如何在无序数组中寻找第K大的数？
//先排序再取第K个元素，复杂度位O(nlogn)
//利用随机快速排序算法（随机选取主元），比较主元位置和K的大小关系，并决定向左或向右递归
//最坏复杂度为O(n^2)，但可以证明平均复杂度为O(n)
//这意味着不存在一组特定数据出现最坏情况


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>     //包含round()函数
#include <iostream>   //包含swap()函数

using namespace std;  //不可省

int randPartition(int A[],int left,int right)  //随机选择主元
{
    //int p=rand()%(right-left+1)+a;
    int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
    swap(A[p],A[left]);
    int temp=A[left];
    while(left<right)
    {
        while(left<right&&A[right]>temp)
            right--;
        A[left]=A[right];
        while(left<right&&A[right]<=temp)  //选一个小于等于，保证与主元相等的元素在同一侧
            left++;
        A[right]=A[left];
    }
    A[left]=temp;
    return left;
}

int randSelect(int A[],int left,int right,int K)   //返回第K大的数
{
    if(left==right)
        return A[left];   //递归边界
    int p=randPartition(A,left,right); //划分后主元位置p
    int M=p+1;  //A[p]是第M大
    if(K==M)
        return A[p];
    else if(K<M)
        return randSelect(A,left,p-1,K);
    else    //如果连续3个if()，编译时会有警告
        return randSelect(A,p+1,right,K);
}

int main()
{
    srand((unsigned)time(NULL));
    //
}
