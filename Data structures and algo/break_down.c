#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct node
{
  float x;
  float y;
  struct node* next;
};

typedef struct node node;
node *start=NULL;

void display()
{
  node *dis = start;
  while(dis!=NULL)
  {
    printf(" %f %f -> ",dis->x,dis->y);
    dis = dis->next;
  }
  printf("NULL\n");
}

void create()
{
  node *traverse = start;
  while(traverse!=NULL)
  {
    node *new_node = (node *)malloc(sizeof(node));
    node *temp_node;
    temp_node = traverse->next;
    float data = (traverse->y - traverse->x)/3;
    new_node->y = traverse->y;
    traverse->y = traverse->x + data;
    new_node->x = new_node->y - data;
    traverse->next = new_node;
    new_node->next = temp_node;
    traverse = temp_node;
  }
  display();
}

int main()
{
  int n;
  printf("How many levels: ");
  scanf("%d",&n);
  printf("Enter the starting and the ending point:  ");
  float a,b;
  scanf("%f %f",&a,&b);
  fflush(stdin);
  if (start==NULL)
  {
    node *first_node = (node *)malloc(sizeof(node));
    first_node->x = a;
    first_node->y = b;
    first_node->next=NULL;
    start = first_node;
  }
  display();
  for (int i=1;i<=n-1;i++)
  {
    create();
  }
}
