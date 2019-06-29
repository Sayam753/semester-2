#include<stdio.h>
#include<string.h>
void fact(int *p,int *q);
void fib(long long int *a);
void fact(int *p,int *q)
{
  if (*p==1)
  {
    printf("%d\n",*q);
    return;
  }
  int t1=*p-1;
  int t2=*q*t1;
  fact(&t1,&t2);
}

void fib(long long int *a)
{
  long long int x,y,z;
  *a = 0;
  *(a+1)=1;
  x = *a;
  y = *(a+1);
  for (int i=2;i<100;i++)
  {
    z = x + y;
    *(a+i) = z;
    x = y;
    y = z;
  }
  for (int i=0;i<20;i++)
  {
    printf("%lld ",*(a+i));
  }
  printf("\n");
}


int main()
{
  int n;
  printf("Enter your choice\n");
  scanf("%d",&n);
  long long int a[100];
  switch(n)
  {
    case 1:
      fact(&n,&n);
      break;
    case 2:
      fib(a);
      break;

  }
}
