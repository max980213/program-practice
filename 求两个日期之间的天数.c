#include <stdio.h>
#include <stdbool.h>

bool ifleapyear(int year)
{
    return (year%400==0||(year%4==0&&year%100!=0));
}

void swap(int* date1,int* date2)
{
    int temp;
    temp=*date1;
    *date1=*date2;
    *date2=temp;
}

int main()
{
    int months[12][2]={{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

    int date1,date2;
    int year1,month1,day1;
    int year2,month2,day2;
    int num=0;

    scanf("%d %d",&date1,&date2);
    if(date1>date2)
        swap(&date1,&date2);

    year1=date1/10000;month1=(date1%10000)/100;day1=date1%100;
    year2=date2/10000;month2=(date2%10000)/100;day2=date2%100;

    while(year1!=year2||month1!=month2||day1!=day2)
    {
        day1++;
        if(day1==months[month1-1][ifleapyear(year1)]+1)
        {
            day1=1;
            month1++;
        }
        if(month1==13)
        {
            year1++;
            month1=1;
        }
        num++;
    }
    printf("%d",num);
    return 0;
}
