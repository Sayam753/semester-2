#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *prev;
  struct node *next;
};

#define allot_memory (struct node *)malloc(sizeof(struct node))
struct node *track_node_1; // for keeping track of first node
struct node *track_node_2; // for keeping track of second node
struct node *track_second_last_node; // for keeping track of second last node
struct node *track_last_node; // for keeping track of current last node
struct node *start; // head of linked list
struct node *print_node; // for printing nodes and moving ahead
struct node *temp_node; // for inserting new node at a particular point
struct node *new_node; // for inserting new node at the end of last node while creating linked list.
int no_of_nodes;

void display(void)
{
  print_node = start;
  for (int i=1;i<=no_of_nodes;i++)
  {
    printf("Data at node %d is %d.\n",i,print_node->data);
    print_node = print_node->next;
  }
}


void create()
{
  start = allot_memory;
  temp_node = allot_memory;
  printf("Enter data at node 1:  ");
  scanf("%d",&(start->data));
  start->prev = NULL;
  start->next = NULL;
  temp_node = start;
  for (int i=2;i<=no_of_nodes;i++)
  {
    new_node = allot_memory;
    printf("Enter data at node %d:  ",i);
    scanf("%d",&(new_node->data));
    temp_node->next = new_node;
    new_node->next = NULL;
    new_node->prev = temp_node;
    temp_node = new_node;
  }
}

int main()
{
  printf("  ## CAUTION - Assumed one based indexing of nodes ##\n");
  printf("How many nodes:\n");
  scanf("%d",&no_of_nodes);
  create();
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
  display();
}
