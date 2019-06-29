#include <stdio.h>
#include<stdlib.h>
#include "header.h"

void add()
{
  student *new_node = (student *)malloc(sizeof(student));
  printf("Enter the details: ");
  fflush(stdin);
  scanf("%d %s %f",&new_node->rollno,new_node->name,&new_node->cgpa);
  new_node->next = NULL;
  if (start==NULL)
  {
    start = new_node;
  }
  else
  {
    student *temp=start;
    while(temp->next !=NULL)
    {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}


void print(student *node)
{
  printf("%d %s %f.\n",node->rollno,node->name,node->cgpa);
}

void printfrom(student *node)
{
  if (node==NULL)
  {
    return;
  }
  else
  {
    print(node);
    printfrom(node->next);
  }
}

void print_all()
{
  printfrom(start);
}

student* find_roll_no(int roll)
{
  student *temp = start;
  while(temp!=NULL)
  {
    if (temp->rollno==roll)
    {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

void delete_by_roll(int roll)
{
  student *temp=start;
  student *prev;
  while(temp!=NULL)
  {
    if (temp->rollno==roll)
    {
      if (temp==start)
      {
        start = temp->next;
        free(temp);
        return;
      }
      else
      {
        prev->next = temp->next;
        free(temp);
        return;
      }
    }
    prev = temp;
    temp = temp->next;
  }
}
