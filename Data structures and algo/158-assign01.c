#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void solution1(void)
{
  int c=0,sum=0;
  for (int i=2;i<=500;i++)
  {
    if (c==20)
    {
      break;
    }
    int flag=0;
    for (int j=2;j<i;j++)
    {
      if (i%j==0)
      {
        flag=1;
        break;
      }
    }
    if (flag==0)
    {
      sum+=i;
      c++;
    }
  }
  printf("Sum of first 20 primes is %d\n",sum);

}

void solution2(void)
{
  printf("Program to print the numbers between 1 and 50, divisible by 3 and not divisible by 2\n");
  printf("Numbers are: ");
  for (int i=1;i<=50;i++)
  {
    if (i%3==0 && i%2==1)
    {
      printf("%d ",i);
    }
  }
  printf("\n");
}

void solution3(void)
{
  printf("Program to calculate Factorial of a number:\n");
  printf("Please enter a number:\n");
  int n;
  scanf("%d",&n);
  if (n<0)
  {
    printf("Factorial of negative numbers is not defined.\n");
  }
  else
  {
    int fact=1;
    for (int i=1;i<=n;i++)
    {
      fact*=i;
    }
    printf("Factorial of %d is %d\n",n,fact);
  }
}

void solution4(void)
{
  printf("Program to calculate no of odd digits in a number:\n");
  printf("Please enter a number:\n");
  long long int a;
  scanf("%lld",&a);
  int c=0,rem;
  long long int temp=a;
  while(a>0)
  {
    rem=a%10;
    if (rem%2==1)
    {
      c++;
    }
    a/=10;
  }
  printf("No of odd digits in %lld is %d\n",temp,c);
}


int fib(int i);

void solution5(void)
{
  printf("Program to print fibonacci series upto 80:\n");
  long long int sum=0,i;
  for (i=1;;i++)
  {
    int temp=fib(i);
    if (temp>80)
    {
      break;
    }
    printf("%d ",temp);
    sum+=temp;
  }
  printf("\nSum of terms of fibonacci series upto 80 is %lld\n",sum);
}

int fib(int i)
{
  if (i==1)
  {
    return (0);
  }
  else if (i==2)
  {
    return (1);
  }
  else{
    return (fib(i-1)+fib(i-2));
  }
}

int main()
{
  int choice;
  printf("Enter the solution you want to run:\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: solution1(); break;
    case 2: solution2(); break;
    case 3: solution3(); break;
    case 4: solution4(); break;
    case 5: solution5(); break;
  }
}
