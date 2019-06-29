#include<stdio.h>
int main()
{
  int b=0;
  int a[1200];
  for (int i=2;b<=1200;i++)
  {
    int flag=0;
    for (int j=2;j<i/2;j++)
    {
      if (i%j==0)
      {
        flag=1;
        break;
      }
    }
    if (flag!=1)
    {
      a[b]=i;
      b++;
    }
  }
  for(int i=0;i<1200;i++)
  {
    printf("%d,",a[i]);
  }
}
