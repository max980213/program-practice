//区间贪心
//题目描述：给出n个开区间，从中选择尽可能多的开区间，使得这些看区间两两没有jiao'ji
//思路：按照区间的左端点从大到小排序
//贪心思想：总是选择左端点最大的区间（或者右端点最小的区间）

#include <stdio.h>
#include <algorithm>

#define maxn 100

using namespace std;

struct Inteval
{
    int x,y; //开区间的左右端点
}I[maxn];

bool cmp(Inteval a,Inteval b)
{
    if(a.x!=b.x)
        return a.x>b.x;
    else
        return a.y<b.y;
}

int main()
{
    int n;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&I[i].x,&I[i].y);
        }
        sort(&I[0],&I[n],cmp);
        //ans记录不相交区间的个数，lastX记录上一个被选中区间的左端点
        int ans=1,lastX=I[0].x;   //sort()排序后，按照左端点从大到小
        for(int i=1;i<n;i++) //第一个已经暂时被记录，所以从下标1第二个开始
        {
            if(I[i].y<=lastX)   //如果该区间右端点在lastX左边，说明这两个区间没有交集了（小于等于->开区间）
            {
                lastX=I[i].x;   //以I[i]为新的选中区间
                ans++;          //不相交区间个数加1
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
