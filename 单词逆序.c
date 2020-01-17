/*
题目描述：逆序输出输入的单词
*/


#include <stdio.h>

//注意：如果键入回车，回车会被scanf视作字符串的结尾标志，但不会将回车符记入，但i依然会自加。
//所以根据输入形式不同，for循环中的初值也许会不同
//若以空格为间隔，最后一个EOF不会读入，但i已经自加，所以初值为i-1

int main()
{
    char array[90][90];
    int i=0;
    while(scanf("%s",array[i++])!=EOF);
    for(i=i-1;i>-1;i--)
    {
        printf("%s",array[i]);
        if(i>0)
            printf(" ");
    }
}
