#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"heading.h"
student *head = NULL;
heap array_implementation[20];
int g_count=0;
int i,j,location,par,flag;
student *temp,*prev;
int temp_array[20];

int main()
{
  int choice;
  while(1)
  {
    printf("Enter your choice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      addStudent();
      break;
      case 2:
      updateStudentByRollNo();
      break;
      break;
      case 3:
      deleteStudentByRollNo();
      break;
      case 4:
      printStudentByRollNo();
      break;
      case 5:
      printAllStudent();
      break;
      case 6:
      buildingHeap();
      break;
      case 8:
      deleteMinimum();
      break;
      case 9:
      getToprankingStudent();
      break;
      case 10:
      prettyprintBHeap(0);
      break;

    }
  }
}
