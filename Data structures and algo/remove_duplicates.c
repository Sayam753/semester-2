#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
typedef struct node node;
node *head;

void create()
{
  node *new_node = (node *)malloc(sizeof(node));
  printf("Enter the data: ");
  scanf("%d",&new_node->data);
  new_node->next = NULL;
  if (head==NULL)
  {
    head=new_node;
    return;
  }
  node *temp=head;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = new_node;
}


void display()
{
  node *temp = head;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void remove_duplicates()
{
  node *temp1 = head,*temp2;
  while(temp1->next!=NULL)
  {
    temp2 = temp1->next;
    while(temp2!=NULL && temp2->data == temp1->data)
    {
      temp2 = temp2->next;
    }
    temp1->next = temp2;
    temp1 = temp2;
    if (temp1==NULL)
    {
      break;
    }
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    while(n--)
    {
      create();
    }
    display();
    remove_duplicates();
    display();
  }
}
