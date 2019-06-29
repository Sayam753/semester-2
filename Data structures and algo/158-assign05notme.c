#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef TOTAL_STUDENTS
#define TOTAL_STUDENTS 5
#endif

struct student
{
  char name[30];
  int roll_no;
  float cgpa;
  struct student *favorite_student;
};

typedef struct student Student;
Student *g_students[TOTAL_STUDENTS];

void populate_student_details()
{
  for (int i=0;i<TOTAL_STUDENTS;i++)
  {
    g_students[i] = (Student *)malloc(sizeof(Student));
    printf("Enter the details of %d student: ",i+1);
    scanf("%s %d %f",g_students[i]->name,&(g_students[i]->roll_no),&(g_students[i]->cgpa));
    g_students[i]->favorite_student = NULL;
  }
}

int find_index(int rollno)
{
  for (int i=0;i<TOTAL_STUDENTS;i++)
  {
    if (g_students[i]->roll_no == rollno)
    {
      return i;
    }
  }
  return -1;
}

void make_favorite_student(int roll1,int roll2)
{
  int position1 = find_index(roll1);
  int position2 = find_index(roll2);
  g_students[position1]->favorite_student = g_students[position2];
  printf("Link is successfully made.\n");
}

void print_fav_chain(Student *sptr)
{
    if (sptr==NULL)
    {
        return;
    }
    else
    {
        printf("\nFirst Name of student is %s.\n",sptr->name);
        printf("Roll No is %d and cgpa is %f.\n",sptr->roll_no,sptr->cgpa);
    }
    print_fav_chain(sptr->favorite_student);
}

void print_from_student(int rollno)
{
  int position = find_index(rollno);
  print_fav_chain(g_students[position]);
}

int main()
{
  int choice;
  int rollno,roll1,roll2;
  int flag=1;
  while(flag!=0)
  {
    printf("Enter your choice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        populate_student_details();
        break;

      case 2:
        printf("Enter the roll_no: ");
        scanf("%d",&rollno);
        int position = find_index(rollno);
        if (position == -1)
        {
          printf("Roll No not found.");
        }
        else printf("Position of %d roll_no is %d.\n",rollno,position);
        break;

      case 3:
        printf("Enter two roll nos: ");
        scanf("%d %d",&roll1,&roll2);
        make_favorite_student(roll1,roll2);
        break;

      case 4:
        printf("Enter the roll_no: ");
        scanf("%d",&rollno);
        print_from_student(rollno);
        break;

    } //switch closed
  printf("Enter 1 to continue the program else press 0: ");
  scanf("%d",&flag);
  }
} //main function closed
