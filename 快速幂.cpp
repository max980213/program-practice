//二分法的逆思想：快速幂的求法
//给定正整数a,b,m,求(a^b)%m
//如果b是奇数，那么有a^b=a^(b-1)*a
//如果b是偶数，那么有a^b=a^(b/2)*a^(b/2)
//显然，如果b是奇数，可以在下一层转化为偶数的情况
//最后，一定会转化为0次方
//显然，用到了递归的思想，复杂度为O(logb)

//等价于
//for(int i=0;i<b;i++)
//    ans=ans*a%m;     //ans初值为1
//但不能明白这种算法数学上为什么对

#include <stdio.h>

typedef long long int LL;

LL binaryPow(LL a,LL b,LL m)
{
    if(b==0)
        return 1;
    if(b%2==1) //奇数
        return (a*binaryPow(a,b-1,m))%m;
    if(b%2==0)
    {
       //这种写法会迭代两次，无法降低复杂度 return (binaryPow(a,b/2,m)*binaryPow(a,b/2,m))%m;
       int mid=binaryPow(a,b/2,m);
       return mid*mid%m;
    }

}

//由此可以引出快速幂的迭代方法，即把b看作2进制来表示
//如，b=13时，13可写成1+4+8
//由此可以逐个检查用2进制表示的数b的每一位，若为1，则表示有该位的2进制次幂，累计该位2^i
//具体实现：1°设初值ans=1，用来存放累计结果
//         2°判断b的二进制末尾是否为1（两种方法：1.作与运算，b&1
//                                              2.简单理解为判断是否为奇数）
//              如果是1的话，令ans×该值
//          3°令a平方，并将b右移一位（除以2）
//          4°只要b大于0，就返回2°

LL binaryPow2(LL a,LL b,LL m)
{
    LL ans=1;
    while(b>0)
    {
        if(b&1==1)
        {
            ans=ans*a%m;
        }
        a=a*a%m;  //因为右移了一位，所以需要a平方
        b>>=1;//b右移一位
    }
    return ans;
}



int main()
{
    LL a,b,m;
    scanf("%lld %lld %lld",&a,&b,&m);
    printf("%lld",binaryPow2(a,b,m));
    return 1;
}
