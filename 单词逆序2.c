#include <stdio.h>
#include <string.h>

int main()
{
    char str[90];
    gets(str);
    int len = strlen(str),r = 0,h = 0;
    char array[90][90];
    for(int i = 0;i < len;i++)
    {
        if(str[i]!=' ')    //如果不是空格，就依次把字符存进来
            array[r][h++]=str[i];
        else    //如果是空格，先补一个结束符
        {
            array[r++][h]='\0';
            h=0;
        }
    }
    for(int i = r;i>-1;i--)   //最后一个没有空格了，r没有自加，所以初值从r开始即可
    {
        printf("%s",array[i]);
        if(i>0)
            printf(" ");
    }
}
