//关于随机数

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    srand((unsigned)time(NULL));    //srand()函数生成随机数种子，因为只能生成伪随机数，所以利用一直在变化的时间来生成不同种子
    for(int i=0;i<10;i++)
    {
        printf("%d ",rand());       //有种子后，就可在需要用随机数的地方使用rand()函数生成随机数，返回int型
                                    //因为以时间为参数生成种子，故每次生成的随机数都不同
                                    //伪随机数：一旦生成，该随机数就被确定，以后不管怎么生成都是它（种子以确定）
                                    //故利用时间作种子
    }
    printf("\n");
    int a=0,b=10;
    for(int i=0;i<10;i++)
    {
        printf("%d ",rand()%(b-a+1)+a);  //  rand()%(b-a+1)+a生成[a,b]范围内的随机数
    }
    printf("\n");
    a=10000;b=60000;
    for(int i=0;i<10;i++)
    {
        printf("%d ",(int)(round(1.0*rand()/RAND_MAX*(b-a)+a)));   //rand()生成的随机数不会超过stdlib.h中的常数RAND_MAX
                                                            //故利用等比例放大的思想
                                                            //可不用round()进行四舍五入  （在math.h中）
    }
    return 1;
}
