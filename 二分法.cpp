//二分法实例
//求根号2的近似值

#include <stdio.h>

#define eps 1e-5

double f(double x)
{
    return x*x;
}

double calSqrt()
{
    double left=1,right=2,mid;     //1到2的闭区间
    while(right-left>eps)
    {
        mid=(left+right)/2;
        if(f(mid)>2)
        {
            right=mid;
        }
        else
        {
            left=mid;
        }
    }
    return mid;
}

int main()
{
    printf("%.5f",calSqrt());
    return 1;
}
