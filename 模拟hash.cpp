#include <stdio.h>
#include <string.h>

int main()
{
    int a[17];
    memset(a,0,sizeof(a));
    int key;
    while((scanf("%d",&key))!=EOF)
    {
        if(key==-1)
            break;
        int flag=0;
        int i=key%13;
        if(a[i]==0)
        {
            a[i]=key;
        }
        else
        {
            while(a[i]!=0)
            {
                if(flag>10000)
                {
                    printf("这个数套娃了！%d\n",key);
                    break;
                }
                i=(i+(2*i-1))%17;
                flag++;
            }
            if(flag<10000)
                a[i]=key;
        }
        for(int k=0;k<17;k++)
        {
            printf("%d ",a[k]);
        }
        printf("\n");
    }
    for(int i=0;i<17;i++)
        printf("%d ",a[i]);
    return 0;
}
