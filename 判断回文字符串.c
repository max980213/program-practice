#include <stdio.h>
#include <string.h>
#define MAX 255

//回文字符串，只需要比较一半

int main()
{
    char array[MAX];
H1: while(gets(array))
    {
    int len=strlen(array);
    for(int i=0;i<len/2;i++)
    {
        if(array[i]!=array[len-i-1])
        {
            printf("No!\n");
            //return 0;
            goto H1;
        }
        else
            continue;
    }
    printf("Yes!\n");
  //  return 0;
    }
}
