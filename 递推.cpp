//递推
//字符串APPAPT中包含两个单词“PAT"，现给定任意字符串，问可以形成几个”PAT"
//直接暴力会超时
//思路：对于字符串中的每个"A",左边P的数量乘以右边T的数量，就是这个A能形成的PAT的数量
//对每个A均作该操作，然后求和

#include <stdio.h>
#include <string.h>  //strlen()

#define MAX 10000
//#define MOD 1000000

char str[MAX];          //存放字符串
int leftNumP[MAX]={0};  //每一位左边含"p"数

int main()
{
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(i>0)
        {
            leftNumP[i]=leftNumP[i-1];//非0位继承上一位结果
        }
        if(str[i]=='P')
        {
            leftNumP[i]++;   //当前位置是P
        }
    }
    int ans=0,rightNumT=0;
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]=='T')
        {
            rightNumT++;
        }
        else if(str[i]=='A')
        {
            ans=(ans+leftNumP[i]*rightNumT);//累积乘积
        }
    }
    printf("%d\n",ans);
    return 1;
}
