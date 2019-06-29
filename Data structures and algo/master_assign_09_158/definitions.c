#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"heading.h"

void printStudentbyhackerrank(int hackerRank)
{
  student *temp = head;
  while(temp!=NULL)
  {
    if (temp->hackerRank == hackerRank)
    {
      printf("Name is %s, roll_no is %d, cgpa is %f and hackerRank is %d.\n",temp->name,temp->roll_no,temp->cgpa,temp->hackerRank);
      return;
    }
    temp = temp->next;
  }
  return;
}

void deleteStudentByhackerrank(int hackerRank)
{
  student *temp = head;
  student *prev;
  while(temp!=NULL)
  {
    if (temp->hackerRank==hackerRank)
    {
      if (temp==head)
      {
        head = temp->next;
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

void addStudent()
{
  student *new_student = (student *)malloc(sizeof(student));
  printf("Enter the name, roll_no, cgpa and hackerRank: ");
  scanf("%s %d %f %d",new_student->name,&(new_student->roll_no),&(new_student->cgpa),&(new_student->hackerRank));
  new_student->next = NULL;
  if (head==NULL)
  {
    head = new_student;
    insert(new_student->hackerRank);
    return;
  }
  else
  {
    student *temp = head;
    while(temp->next!=NULL)
    {
      temp = temp->next;
    }
    temp->next = new_student;
  }
  insert(new_student->hackerRank);
}

void printAllStudent()
{
  student *temp = head;
  while(temp!=NULL)
  {
    printf("Name is %s, roll_no is %d, cgpa is %f and hackerRank is %d.\n",temp->name,temp->roll_no,temp->cgpa,temp->hackerRank);
    temp = temp->next;
  }
}

void updateStudentByRollNo()
{
  int roll;
  printf("Enter a roll_no to update: ");
  scanf("%d",&roll);
  temp = head;
  flag=0;
  while(temp!=NULL)
  {
    if (temp->roll_no == roll)
    {
      printf("Enter the name, roll_no, cgpa and hackerRank: ");
      scanf("%s %d %f %d",temp->name,&(temp->roll_no),&(temp->cgpa),&(temp->hackerRank));
      flag=1;
      printf("List updated.\n");
      return;
    }
    temp = temp->next;
  }
  if (flag==0)
  {
    printf("roll_no not found.\n");
  }
}

void deleteStudentByRollNo()
{
  int roll;
  printf("Enter a roll_no to delete: ");
  scanf("%d",&roll);
  temp = head;
  flag=0;
  while(temp!=NULL)
  {
    if (temp->roll_no==roll)
    {
      if (temp==head)
      {
        flag=1;
        head = temp->next;
        free(temp);
        return;
      }
      else
      {
        flag=1;
        prev->next = temp->next;
        free(temp);
        return;
      }
    }
    prev = temp;
    temp = temp->next;
  }
  if (flag==0)
  {
    printf("roll_no not found.\n");
  }
}

void printStudentByRollNo()
{
  int roll;
  printf("Enter a roll_no to print: ");
  scanf("%d",&roll);
  temp = head;
  flag=0;
  while(temp!=NULL)
  {
    if (temp->roll_no == roll)
    {
      printf("Name is %s, roll_no is %d, cgpa is %f and hackerRank is %d.\n",temp->name,temp->roll_no,temp->cgpa,temp->hackerRank);
      flag=1;
      return;
    }
    temp = temp->next;
  }
  if (flag==0)
  {
    printf("roll_no not found.\n");
  }
}

void insert(int hackerRank)
{
  array_implementation[g_count].hackerRank = hackerRank;
  location = g_count;
  g_count++;
	while(location>0)
	{
		par=(location-1)/2;
		if(hackerRank>=array_implementation[par].hackerRank)
		{
			array_implementation[location].hackerRank=hackerRank;
			return;
		}
    else
    {
      location = percolateup(location,par);
    }

	}/*End of while*/
	array_implementation[0].hackerRank=hackerRank; /*assign num to the root node */
}

void getToprankingStudent()
{
  if (g_count==0)
  {
    printf("Heap is empty.\n");
    return;
  }
  else
  {
    printStudentbyhackerrank(array_implementation[0].hackerRank);
    deleteStudentByhackerrank(array_implementation[0].hackerRank);
    array_implementation[0].hackerRank = array_implementation[g_count-1].hackerRank;
    g_count--;
    if (g_count>0)
    {
      percolatedown(0);
    }
  }
}

int percolateup(int location,int par)
{
  array_implementation[location].hackerRank=array_implementation[par].hackerRank;
  location=par;
  return location;
}

void percolatedown(int nodeIndex)
{
  int leftChildIndex, rightChildIndex, minIndex, tmp;
  leftChildIndex = 2*nodeIndex +1;
  rightChildIndex = 2*nodeIndex +2;
  if (rightChildIndex >= g_count)
  {
    if (leftChildIndex >= g_count)
      return;
    else
      minIndex = leftChildIndex;
  }
  else
  {
    if (array_implementation[leftChildIndex].hackerRank <= array_implementation[rightChildIndex].hackerRank)
      minIndex = leftChildIndex;
    else
      minIndex = rightChildIndex;
  }
  if (array_implementation[nodeIndex].hackerRank > array_implementation[minIndex].hackerRank)
  {
    tmp = array_implementation[minIndex].hackerRank;
    array_implementation[minIndex].hackerRank = array_implementation[nodeIndex].hackerRank;
    array_implementation[nodeIndex].hackerRank = tmp;
    percolatedown(minIndex);
  }
}

void prettyprintBHeap(int index)
{
  for (int i=0;i<g_count;i++)
  {
    printf("%d ",array_implementation[i].hackerRank);
  }
  printf("\n");
  for(i=0;i<g_count;i++)
  {
    for(j=0;(j<(int)pow(2,i))&&(j+(int)pow(2,i)<10);j++)
    {
      printf("%d ",array_implementation[j+(int)pow(2,i)-1].hackerRank);
    }
    printf("\n");
  }
}

void buildingHeap()
{
  int max_nodes = g_count;
  for (i=0;i<max_nodes;i++)
  {
    temp_array[i] = array_implementation[i].hackerRank;
  }
  g_count = 0;
  for (i=0;i<max_nodes;i++)
  {
    insert(temp_array[i]);
  }
}

void deleteMinimum()
{
  if (g_count==0)
  {
    printf("Heap is empty.\n");
    return;
  }
  else
  {
    printStudentbyhackerrank(array_implementation[0].hackerRank);
    deleteStudentByhackerrank(array_implementation[0].hackerRank);
    array_implementation[0].hackerRank = array_implementation[g_count-1].hackerRank;
    g_count--;
    if (g_count>0)
    {
      percolatedown(0);
    }
  }
}
