//随机选择算法实例
//给定一个由整数组成的集合，集合中的整数各不相同，现在将它分为两个集合，使这两个集合的并为原集合，交为空集，同时在两个自己和的元素【个数】
//之差尽可能小的情况下，要求两个集合各元素和的差尽可能大
//思路：先考虑个数，如果原集合中元素个数为偶数n，则两个集合元素个数为n/2
//若为奇数，则为n/2和n/2+1
//暴力法，可直接将原集合排序，再从中间分开，复杂度为O(nlogn)
//但考虑随机选择算法，筛出第n/2大元素，反而不需要进行排序，平均期望复杂度为O(n)



#include <stdio.h>
#include <algorithm>  //包含swap()函数
#include <stdlib.h>
#include <time.h>
#include <math.h>     //包含round()函数

#define MAX 100000

using namespace std;  //不可省

int randPartition(int A[],int left,int right)  //随机选择主元，并划分
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
        while(left<right&&A[left]<=temp)  //选一个小于等于，保证与主元相等的元素在同一侧
            left++;
        A[right]=A[left];
    }
    A[left]=temp;
    return left;
}

void randSelect(int A[],int left,int right,int K)   //返回第K大的数
{
    if(left==right)
        return;   //递归边界
    int p=randPartition(A,left,right); //划分后主元位置p
    int M=p+1;  //A[p]是第M大
    if(K==M)
        return;
    if(K<M)
        randSelect(A,left,p-1,K);
    else    //如果连续3个if()，编译时会有警告
        randSelect(A,p+1,right,K);
}

int A[MAX];//存放原集合
int n;//原集合元素个数

int main()
{
    srand((unsigned)time(NULL));  //初始化随机数种子
    int S=0,S1=0;  //初始化两个集合的元素和
    scanf("%d",&n);//元素个数
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        S+=A[i];  //累计所有整数和
    }
    randSelect(A,0,n-1,n/2);
    for(int i=0;i<n/2;i++)
    {
        S1+=A[i];//计算左半边，再用总的和作差
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("%d",abs((S-S1)-S1));
    return 1;
    //
}
