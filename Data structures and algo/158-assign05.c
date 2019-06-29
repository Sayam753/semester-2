#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef TOTAL_CITIES
#define TOTAL_CITIES 5
#endif

struct student
{
  char name[30];
  int roll_no;
  float cgpa;
  int city_code;
  struct student *neighbor_student;
};

typedef struct student Student;
Student *g_students_city[TOTAL_CITIES];

void join_to_list(Student *start,Student *new_student)
{
  if (start->neighbor_student==NULL)
  {
    start->neighbor_student = new_student;
    return;
  }
  else
  {
    join_to_list(start->neighbor_student,new_student);
  }
}

void populate_student_details()
{
  Student *new_student = (Student *)malloc(sizeof(Student));
  printf("Enter the details of student: ");
  scanf("%s %d %f %d",new_student->name,&(new_student->roll_no),&(new_student->cgpa),&(new_student->city_code));
  new_student->neighbor_student = NULL;
  if (g_students_city[new_student->city_code]==NULL)
  {
    g_students_city[new_student->city_code] = new_student;
  }
  else
  {
    Student *start = g_students_city[new_student->city_code];
    join_to_list(start,new_student);
  }
}

void are_neighbours(int roll1,int roll2)
{
  int value1=0,value2=0;
  int city1,city2;
  for (int i=0;i<TOTAL_CITIES;i++)
  {
    Student *start = g_students_city[i];
    while(start!=NULL)
    {
      if (start->roll_no==roll1 && !value1)
      {
        city1 = i;
        value1 = 1;
      }
      if (start->roll_no==roll2 && !value2)
      {
        city2 = i;
        value2 = 1;
      }
      if (value1 ==1 && value2 == 1)
      {
        break;
      }
      start = start->neighbor_student;
    }
    if (value1 ==1 && value2 == 1)
    {
      break;
    }
  }
  if (city1 == city2)
  {
    printf("True, these rollnos are neighbours.\n");
  }
  else
  {
    printf("False, these rollnos are not neighbours.\n");
  }
}

void print_students_neighbors(Student *sptr)
{
    if (sptr==NULL)
    {
        return;
    }
    else
    {
        printf("\nFirst Name of student is %s.\n",sptr->name);
        printf("Roll No is %d, cgpa is %f and city is %d.\n",sptr->roll_no,sptr->cgpa,sptr->city_code);
    }
    print_students_neighbors(sptr->neighbor_student);
}

void print_students_from_city(int city_code)
{
  print_students_neighbors(g_students_city[city_code]);
}

int main()
{
  int choice;
  int citycode,roll1,roll2;
  int flag=1;
  for (int i=0;i<TOTAL_CITIES;i++)
  {
    g_students_city[i] = NULL;
  }
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
        printf("Enter the citycode: ");
        scanf("%d",&citycode);
        print_students_from_city(citycode);
        break;

      case 3:
        printf("Enter two roll nos: ");
        scanf("%d %d",&roll1,&roll2);
        are_neighbours(roll1,roll2);
        break;


    } //switch closed
  fflush(stdin);
  printf("Enter 1 to continue the program else press 0: ");
  scanf("%d",&flag);
  }
} //main function closed
