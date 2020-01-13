#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);

    int array[N];
    for(int i = 0;i < N;i++)
    {
        int M,flag = 0 , temp = 0;
        scanf("%d",&M);
        for(int j = 0;j < M;j++)
        {
            scanf("%d",&temp);
            flag = flag + temp;
        }
        array[i] = flag;
    }
    for(int i = 0;i<N;i++)
    {
        printf("%d\n\n",array[i]);
    }
    return 0;
}
