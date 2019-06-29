#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  int data;
  struct node *next;
}*point1,*point2,*point3,*point4,*point5,*point6,*point_asc1,*point_asc2;

struct node *track_node_1; // for keeping track of first node
struct node *track_node_2; // for keeping track of second node
struct node *track_second_last_node; // for keeping track of second last node
struct node *track_last_node; // for keeping track of current last node
struct node *start; // head of linked list
struct node *print_node; // for printing nodes and moving ahead
struct node *temp_node; // for inserting new node at a particular point
struct node *new_node; // for inserting new node at the end of last node while creating linked list.

#define allot_memory (struct node *)malloc(sizeof(struct node))
int no_of_nodes=0;

void update(void)
{
  // updating all tracks
  track_node_1 = start;
  if (no_of_nodes==1)
  {
    track_node_2 = start;
    track_last_node = start;
    track_second_last_node = start;
  }
  else if (no_of_nodes==2)
  {
    track_last_node = start->next;
    track_second_last_node = start;
    track_node_2 = track_last_node;
  }
  else
  {
    point1 = start;
    for(int i=1;i<=no_of_nodes;i++)
    {
      if (i==no_of_nodes-1)
      {
        track_second_last_node = point1;
      }
      if (i==no_of_nodes)
      {
        track_last_node = point1;
      }
      if (i==2)
      {
        track_node_2 = point1;
      }
      point1 = point1->next;
    }
  }
}

void display(void)
{
  print_node = start;
  for (int i=1;i<=no_of_nodes;i++)
  {
    printf("Data at node %d is %d.\n",i,print_node->data);
    print_node = print_node->next;
  }
}

void swap(int pos1, int pos2)
{
    struct node *node1, *node2, *prev1, *prev2, *temp;
    int i;
    int maxPos = (pos1 > pos2) ? pos1 : pos2;
    int totalNodes = no_of_nodes;
    i = 1;
    temp  = start;
    prev1 = NULL;
    prev2 = NULL;

    while (temp != NULL && (i <= maxPos))
   {
       if (i == pos1 - 1)
           prev1 = temp;
       if (i == pos1)
           node1 = temp;

       if (i == pos2 - 1)
           prev2 = temp;
       if (i == pos2)
           node2 = temp;

       temp = temp->next;
       i++;
   }

    prev1->next = node2;
    prev2->next = node1;
    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
    if (prev1 == NULL)
        start = node2;
    else if (prev2 == NULL)
        start = node1;
}

void ascending_order(void)
{
  for (int i=1;i<=no_of_nodes;i++)
  {
    point_asc1 = start;
    for (int j=1;j<i;j++)
    {
      point_asc1 = point_asc1->next;
    }
    int min = point_asc1->data,location;
    int flag=0;
    for (int j=i+1;j<=no_of_nodes;j++)
    {
      point_asc2 = start;
      for (int k=1;k<j;k++)
      {
        point_asc2 = point_asc2->next;
      }
      if ((point_asc2->data)<min)
      {
        flag=1;
        min = point_asc2->data;
        location=j;
      }
    }
    if (flag==1)
    {
      swap(i,location);
    }
  }
  update();
}

void create(int no_of_nodes)
{
  start = allot_memory;

  printf("Enter data at node 1:  ");
  scanf("%d",&(start->data));
  start->next = NULL;

  track_node_1 = start;
  track_node_2 = start;
  track_second_last_node = start;
  track_last_node = start;

  for (int i=2;i<=no_of_nodes;i++)
  {
    new_node = allot_memory;
    printf("Enter data at node %d:  ",i);
    scanf("%d",&(new_node->data));
    new_node->next = NULL;
    track_last_node->next = new_node;
    track_last_node = new_node;
    if (i==2)
    {
      track_node_2 = track_last_node;
    }
    if (i==no_of_nodes-1)
    {
      track_second_last_node = track_last_node;
    }
  }
}

void insert(void)
{
  if (no_of_nodes==0)
  {
    temp_node = allot_memory;
    printf("Enter the data at first node:\t");
    scanf("%d",&(temp_node->data));
    temp_node->next = NULL;
    start = temp_node;
    track_last_node = temp_node;
    track_node_1 = temp_node;
    track_node_2 = temp_node;
    track_second_last_node = temp_node;
  }
  else
  {
    printf("At which index you want to insert?\t");
    int choice;
    scanf("%d",&choice);
    while(choice<=0)
    {
      printf("As stated earlier, I have assumed 1 based indexing. Please re-enter the index:  ");
      scanf("%d",&choice);
    }

    if (choice!=no_of_nodes+1 && choice>no_of_nodes)
    {
      printf("Inserting new node at %dth index as the choice of index entered is out of scope.\n",no_of_nodes+1);
    }

    temp_node = allot_memory;
    printf("Enter the data:\t");
    scanf("%d",&(temp_node->data));

    if (choice==1)
    {
      start = temp_node;
      start->data = temp_node->data;
      start->next = track_node_1;
      track_node_1 = start;
      track_node_2 = start->next;
      if (no_of_nodes==1)
      {
        track_second_last_node = temp_node;
      }
    }

    else if (choice>no_of_nodes)
    {
      track_second_last_node = track_last_node;
      track_last_node->next = temp_node;
      temp_node->next = NULL;
      track_last_node = temp_node;
    }
    else
    {
      point1 = start;
      for (int i=1;i<=no_of_nodes;i++)
      {
        if (choice==i+1)
        {
          point2 = point1->next;
          break;
        }
        point1 = point1->next;
      }
      point1->next = temp_node;
      temp_node->next = point2;
      if(choice==2)
      {
        track_node_2 = temp_node;
      }
      else if(choice== no_of_nodes)
      {
        track_second_last_node = temp_node;
        track_last_node = temp_node->next;
      }
    }
  }
  no_of_nodes++;
}

void delete(void)
{
  printf("Enter the index you wish to delete:  ");
  int choice;
  scanf("%d",&choice);
  while(choice<=0 || choice>no_of_nodes)
  {
    printf("Please re-enter the index(1 to %d):  ",no_of_nodes);
    scanf("%d",&choice);
  }

  if (choice == 1)
  {
    free(track_node_1);
    start = track_node_2;
    track_node_2 = start->next;
    track_node_1 = start;
  }
  else if (choice==2)
  {
    point1 = start;
    point1 = point1->next;
    point2 = point1; // for freeing up memory of second node.
    point1 = point1->next;
    start->next = point1;
    track_node_2 = point1;
    free(point2);
  }
  else if (choice==no_of_nodes)
  {
    free(track_last_node);
    point1 = start;
    for (int i=1;i<no_of_nodes-1;i++)
    {
      point1 = point1->next;
    }
    point1->next = track_second_last_node;
    track_second_last_node->next = NULL;
    track_last_node = track_second_last_node;
    track_second_last_node = point1;
  }
  else
  {
    point1 = start;
    for (int i=1;i<=no_of_nodes;i++)
    {
      if (choice-1==i+1)
      {
        point3 = point1->next;
      }
      else if (choice+1==i+1)
      {
          point2 = point1->next;
          break;
      }
      point1 = point1->next;
    }
    free(point1);
    if (choice==no_of_nodes-1)
    {
      track_second_last_node = point3;
    }
    point3->next = point2;
  }
  no_of_nodes--;
  if (no_of_nodes==0)
  {
    printf("Nothing left in the linked list. Please create at least one node:\n");
    insert();
  }
  if (no_of_nodes==1)
  {
    track_last_node = start;
    track_node_1 = start;
    track_node_2 = start;
    track_second_last_node = start;
  }
}

void sum(void)
{
  int sumi=0;
  print_node = start;
  for (int i=1;i<=no_of_nodes;i++)
  {
    sumi+=(print_node->data);
    print_node = print_node->next;
  }
  printf("Sum of data in all nodes: %d.\n",sumi);

}

void reverse(void)
{
  point1 = start;
  start = start->next;
  point2 = start;
  point1->next = NULL;
  for(;start!=NULL;)
  {
    start = start->next;
    point2->next = point1;
    point1 = point2;
    point2 = start;
  }
  start=point1;
  update();
}

int main(void)
{
  printf("  ## CAUTION - Assumed one based indexing of nodes ##\n");
  printf("How many nodes:\n");
  scanf("%d",&no_of_nodes);
  create(no_of_nodes);
  int flag=0;
  while(flag!=1)
  {
    printf("Menu\n1.Display\n2.Insert\n3.Delete\n4.No of nodes\n5.Sum of data at all nodes\n6.Ascending order of the data\n7.Reversing the list\n");
    int choice;
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        display();break;
      case 2:
        insert();break;
      case 3:
        delete();break;
      case 4:
        printf("No of nodes in the linked list: %d.\n",no_of_nodes);
        break;
      case 5:
        sum();break;
      case 6:
        ascending_order();break;
      case 7:
        reverse();break;
    }
    printf("Press 0 to continue the program else press 1:\t");
    scanf("%d",&flag);
  }
}
