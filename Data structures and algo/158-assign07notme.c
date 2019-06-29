#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef max_size
#define max_size 50
#endif

#ifndef BILLION
#define BILLION 1000000000.0;
#endif

typedef struct timespec timespec;
int recursive_sum(int n)
{
  if (n==1)
  {
    return n;
  }
  else
  {
    return (n+recursive_sum(n-1));
  }
}


int main(int argc, char *argv[])
{
  int no_of_elements;
  int array[max_size];
  if(argc==1)
  {
    printf("Enter the no of elements:\n");
    scanf("%d",&no_of_elements);
    for (int i=0;i<no_of_elements;i++)
    {
      scanf("%d",&array[i]);
    }
  }
  else
  {
    no_of_elements = atoi(argv[1]);
    for (int i=0;i<no_of_elements;i++)
    {
      array[i] = atoi(argv[i+2]);
    }
  }
  timespec start,end;
  int temp;

  int sum=0;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
  for (int i=1;i<=no_of_elements;i++)
  {
    sum+=i;
  }
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
  double time_spent = (end.tv_sec - start.tv_sec) +
                      (end.tv_nsec - start.tv_nsec) / BILLION;
  printf("Sum using loops is %d and time taken is %f seconds.\n",sum,time_spent);

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
  sum = recursive_sum(no_of_elements);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
  time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
  printf("Sum using recursion is %d and time taken is %f seconds.\n",sum,time_spent);

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
  sum = (no_of_elements*(array[0]+array[no_of_elements-1]))/2;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
  time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
  printf("Sum using gauss is %d and time taken is %f seconds.\n",sum,time_spent);

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
  sum = ((no_of_elements)*(no_of_elements+1))/2;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
  time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
  printf("Sum using formula is %d and time taken is %f seconds.\n",sum,time_spent);

  int left=0,right=no_of_elements-1;
  sum=0;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
  while(left<right)
  {
    sum = sum + array[left] + array[right];
    left++;
    right--;
  }
  if (no_of_elements%2!=0)
  {
    sum +=array[left];
  }
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
  time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
  printf("Sum using pointers is %d and time taken is %f seconds.\n",sum,time_spent);

}
