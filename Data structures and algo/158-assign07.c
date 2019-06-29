#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
int g_count;
#ifndef BILLION
#define BILLION 1000000000.0;
#endif
void print_cantor_set();
struct cantor_set
{
  float start;
  float end;
  struct cantor_set *next_line;
};
typedef struct timespec timespec;
typedef struct cantor_set cantor_set;
cantor_set *head=NULL;

void delete_linked_list()
{
  if(head==NULL)
  {
    return;
  }
  cantor_set *traverse = head;
  cantor_set *traverse_next = head->next_line;
  while(traverse_next!=NULL)
  {
    free(traverse);
    traverse = traverse_next;
    traverse_next = traverse_next->next_line;
  }
  head = NULL;
}

void generate_using_recursion(cantor_set *traverse,int original_level,int level)
{
  cantor_set *new_node = (cantor_set *)malloc(sizeof(cantor_set));
  cantor_set *temp_node;
  temp_node = (traverse)->next_line;
  float data = ((traverse)->end - (traverse)->start)/3;
  new_node->end = (traverse)->end;
  (traverse)->end = (traverse)->start + data;
  new_node->start = new_node->end - data;
  cantor_set *travelling = head;
  for (int i=1;i<=2*(original_level-level);i++)
  {
    travelling = travelling->next_line;
  }
  travelling->next_line = new_node;
  new_node->next_line = temp_node;
  if (g_count==(int)pow(2,original_level-1))
  {
    return;
  }
  else
  {
    g_count++;
  }
  generate_using_recursion(temp_node,original_level,level-1);
}

void print_cantor_set()
{
  cantor_set *dis = head;
  while(dis!=NULL)
  {
    printf(" %f %f -> ",dis->start,dis->end);
    dis = dis->next_line;
  }
  printf("NULL\n");
}

void create()
{
  cantor_set *traverse = head;
  while(traverse!=NULL)
  {
    cantor_set *new_node = (cantor_set *)malloc(sizeof(cantor_set));
    cantor_set *temp_node;
    temp_node = traverse->next_line;
    float data = (traverse->end - traverse->start)/3;
    new_node->end = traverse->end;
    traverse->end = traverse->start + data;
    new_node->start = new_node->end - data;
    traverse->next_line = new_node;
    new_node->next_line = temp_node;
    traverse = temp_node;
  }
}

int main(int argc, char *argv[])
{
  timespec start,end;
  if (!strcmp(argv[1],"0"))
  {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
    float starting_point = 0;
    float ending_point = 1;
    if (head==NULL)
    {
      cantor_set *new_node = (cantor_set *)malloc(sizeof(cantor_set));
      new_node->start = starting_point;
      new_node->end = ending_point;
      new_node->next_line = NULL;
      head = new_node;
    }
    int level=3;
    for (int i=1;i<=level;i++)
    {
      create();
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
    double time_spent = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("Time taken to create 3 levels is %f seconds.\n",time_spent);
    print_cantor_set();
  }
  else if (!strcmp(argv[1],"1"))
  {
    //delete_linked_list();
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
    float starting_point = 0;
    float ending_point = 1;
    //head = NULL;
    if (head==NULL)
    {
      cantor_set *new_node = (cantor_set *)malloc(sizeof(cantor_set));
      new_node->start = starting_point;
      new_node->end = ending_point;
      new_node->next_line = NULL;
      head = new_node;
    }
    int level = atoi(argv[2]);
    for (int i=1;i<=level;i++)
    {
      create();
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
    double time_spent = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("Time taken to create %d levels is %f seconds.\n",level,time_spent);
    print_cantor_set();
  }
  else if (!strcmp(argv[1],"2"))
  {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
    float starting_point = 0;
    float ending_point = 1;
    //head = NULL;
    if (head==NULL)
    {
      cantor_set *new_node = (cantor_set *)malloc(sizeof(cantor_set));
      new_node->start = starting_point;
      new_node->end = ending_point;
      new_node->next_line = NULL;
      head = new_node;
    }
    int level = log(atoi(argv[2]))/log(2);
    for (int i=1;i<=level;i++)
    {
      create();
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
    double time_spent = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("Time taken to create %d levels is %f seconds.\n",level,time_spent);
    print_cantor_set();
  }
  else
  {
    printf("How many levels? ");
    int level;
    scanf("%d",&level);
    if (head==NULL)
    {
      cantor_set *new_node = (cantor_set *)malloc(sizeof(cantor_set));
      new_node->start = 0;
      new_node->end = 1;
      new_node->next_line = NULL;
      head = new_node;
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
    for (int i=1;i<=level;i++)
    {
      g_count = 1;
      generate_using_recursion(head,i,i);
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
    double time_spent = (end.tv_sec - start.tv_sec) +
                        (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("Time taken to create %d levels is %f seconds.\n",level,time_spent);
    print_cantor_set();
  }
}
