/*
题目描述：输入两数并求和，输入要转换的数制并将结果进行转换
*/

#include <stdio.h>
#include <math.h>
#define EFS 10e-8

//p进制转10进制：每一位乘以p的对应次方，再求和
//10进制转p进制：除p求模
//可以将每一位存放在数组里，但我不想这么做
//因为涉及到了double型的函数(pow())，所以需要进行修正

int main()
{
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);
    int sum=a+b;
    int ans=0,i=0;
    while(sum!=0)
    {
       // printf("%d\n",(sum%n)*(int)(pow(10,i)));
        ans+=(int)((sum%n)*pow(10,i++)+EFS);
       // printf("%d\n",ans);
        sum/=n;
    }
    printf("%d",ans);
    return 0;
}
