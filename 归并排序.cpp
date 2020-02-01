//归并排序
//将序列分成若干小组排序，然后再合并排序

#include <stdio.h>

#define MAX 100

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

//递归实现

void merge(int A[],int L1,int R1,int L2,int R2)  //将数组的[L1,R1],[L2,R2]区间合并为有序区间
{
    int i=L1,j=L2;
    int temp[MAX],index=0;   //存放合并后的数组。index为其下标
    while(i<=R1&&j<=R2)
    {
        if(A[i]<=A[j])
        {
            temp[index++]=A[i++];
        }
        else
        {
            temp[index++]=A[j++];
        }
    }
    while(i<=R1)
        temp[index++]=A[i++];  //将A[L1,R1]剩余元素加入序列temp
    while(j<=R2)
        temp[index++]=A[j++];  //   [L2,R2]
    for(i=0;i<index;i++)
        A[L1+i]=temp[i];  //合并后的数组赋值回数组A
}

void mergeSort(int A[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(A,left,mid);    //递归，将左区间归并排序
        mergeSort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);  //将左右区间合并
    }
}

//非递归实现，步长为2（2-路归并）

void mergeSort2(int A[],int n)
{
    //step为组内元素个数，step/2为左子区间元素个数
    for(int step=2;step/2<=n;step*=2)  //每step个元素一组，组内前后两半合并
    {
        for(int i=1;i<=n;i+=step)  //对每一组
        {
            int mid=i+step/2-1;
            if(mid+1<=n)
            {
                merge(A,i,mid,mid+1,min(i+step-1,n));
            }
        }
    }
}


int main()
{
    //
}
