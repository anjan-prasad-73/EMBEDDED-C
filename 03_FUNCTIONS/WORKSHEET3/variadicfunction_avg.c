#include<stdio.h>
#include<stdarg.h>
int variadic_avg(int count,...)
{
    va_list arg;
    va_start(arg,count);
    int total=0;
    for(int i=0;i<count;i++)
    {
        total+=va_arg(arg,int);
    }
int avg=total/count;
return avg;
}
int main()
{
  int avg=variadic_avg(4,10,20,30,40);
  printf("%d",avg);
  return 0;
}