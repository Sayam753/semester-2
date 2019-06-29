#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

student *start=NULL;

int main()
{
    int roll;
    int choice;
    student *result;
    while(1)
    {
      printf("Enter the choice: ");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
          add();
          break;
        case 2:
        {
          printf("Enter the rollno to find: ");
          scanf("%d",&roll);
          result=find_roll_no(roll);
          if (result==NULL)
          {
            printf("No details found.\n");
          }
          else
          {
            printf("Details found. %d %s %f\n",result->rollno,result->name,result->cgpa);
          }
          break;
        }
        case 3:
          print_all();
          break;
        case 4:
          printf("Enter the rollno to delete: ");
          scanf("%d",&roll);
          delete_by_roll(roll);
          break;
      }
    }
}
