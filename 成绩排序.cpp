/*
题目描述：先输入考场数，先输入考场人数，再依次输入该考场考生的学号和成绩，再输入下一个考场的人数，以此类推
          对考生成绩进行排序，如果成绩相同，则按照学号升序排序，要求：
          输出学号，总排名，考场号，考场内名次
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>

#define MAX 256

using namespace std;

struct student
{
    char id[15]; //准考证号
    int score;   //分数
    int location_id;    //考场号
    int local_rank;     //考场内排名
    int total_rank;
}stu[256];

bool cmp(student a,student b)
{
    if(a.score!=b.score)
        return a.score>b.score;       //按成绩从高到低
    else                              //如果成绩相同，按照准考证号从小到大
        return strcmp(a.id,b.id)<0;
}

int main()
{
    int n,k,num=0;  //n为考场数,k为该考场内人数,num为学生总数
    scanf("%d",&n);  //记录考场数
    for(int i=0;i<n;i++)//按照考场数依次读入
    {
        scanf("%d",&k);  //该考场人数
        for(int j=0;j<k;j++)
        {
            scanf("%s %d",stu[num].id,&stu[num].score);//读入学号和成绩，利用num记录总人数，对应数组下标+1
            stu[num++].location_id=i+1;
        }
        sort(&stu[num-k],&stu[num],cmp);
        stu[num-k].local_rank=1;    //该考场第一个人的排名是第一名
        for(int j=num-k+1;j<num;j++) //对该考场的剩余考生的考场排名进行修改
        {
            if(stu[j].score==stu[j-1].score)
                stu[j].local_rank=stu[j-1].local_rank;   //如果分数一样的话，就让他们排名相同
            else
                stu[j].local_rank=j-(num-k)+1;                      //如果不一样的话，排名应该是已经排名的人数+1
        }
    }
    sort(stu,&stu[num],cmp);
    stu[0].total_rank=1;
    for(int i=1;i<num;i++)
    {
        if(stu[i].score==stu[i-1].score)
            stu[i].total_rank=stu[i-1].total_rank;
        else
            stu[i].total_rank=i+1;
    }
    printf("%d\n",num);//总人数
    for(int i=0;i<num;i++)
    {
        printf("%s %d %d %d\n",stu[i].id,stu[i].total_rank,stu[i].location_id,stu[i].local_rank);
    }
    return 0;
}
