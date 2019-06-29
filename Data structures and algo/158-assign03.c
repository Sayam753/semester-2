#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *p, int *q);
void swap(int *p, int *q)
{
  *p = *p+*q;
  *q = *p-*q;
  *p = *p-*q;
}

struct faculty
{
  char name[100];
  int salary;
};

void increment_salary(struct faculty *f1, int *result);


void pattern(int *p)
{
  *p = 0;
  *(p+1) = 1;
  *(p+2) = 1;
  for (int i=3;i<=29;i++)
  {
    *(p+i) = *(p+i-1) + *(p+i-3);
  }

}

void reverse(char *temp,int *length)
{
  int l = *length;
  for (int i=0;i<l/2;i++)
  {
    char c;
    c = *(temp+i);
    *(temp+i) = *(temp-i-1+l);
    *(temp-i-1+l) = c;
  }
}

int main()
{
  int n;
  printf("Enter your choice\n");
  scanf("%d",&n);
  int *numbers = (int *)malloc(30*sizeof(4));
  struct faculty facuilty;
  switch(n)
  {
    case 1:
      pattern(numbers);
      for (int i=0;i<30;i++)
      {
        printf("%d ",*(numbers+i));
      }
      printf("\n");
      break;
    case 2:
      printf("How many character?\t");
      int *n = (int *)malloc(4);
      scanf("%d",n);
      char *string = (char *)malloc(*n+1);
      scanf("%s",string);
      reverse(string,n);
      for (int i=0;i<(*n);i++)
      {
        printf("%c",*(string+i));
      }
      printf("\n");
      break;
    case 3:
      printf("Enter first integer:\n");
      int *p = (int *)malloc(4);
      scanf("%d",p);
      printf("Enter second integer:\n");
      int *q = (int *)malloc(4);
      scanf("%d",q);
      swap(p,q);
      printf("The reversed values are:\n");
      printf("First: %d\n",*p);
      printf("Second: %d\n",*q);
      break;
    case 4:

      printf("Enter the name of faculty:\n");
      scanf("%s",facuilty.name);
      printf("Enter the salary:\n");
      scanf("%d",&facuilty.salary);
      int *result = (int *)malloc(4);
      increment_salary(&facuilty,result);
      printf("The incremented salary is %d.\n",*result);
      break;


  }
}

void increment_salary(struct faculty *f1, int *result)
{
  *result = (f1->salary) + 0.2*(f1->salary);
}
