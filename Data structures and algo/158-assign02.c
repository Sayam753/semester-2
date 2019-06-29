#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void print_data(int position);
void find_students_roll(void);
void find_students_course_id(void);
void add_student(void);
void summary(void);


struct student
{
  char first_name[20];
  char last_name[20];
  char roll_no[20];
  int name[5];
};


int t=0;
struct student s[50];

int main()
{
  int choice;
  int flag=0;
  while(flag!=1)
  {
    printf("Enter the function you want to run:\n");
    printf("Menu\n");
    printf("1. add_student\n2. find student by roll_no\n3. find student by course-id\n4. summary\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: add_student(); break;
      case 2: find_students_roll(); break;
      case 3: find_students_course_id(); break;
      case 4: summary(); break;
      default:
        exit(1);
    }
    printf("press 0 to continue the program else press 1 to quit:\n");
    scanf("%d",&flag);
  }
}

void add_student(void)
{
  printf("Please enter the first name:\n");
  scanf("%s",s[t].first_name);
  printf("Please enter the last name:\n");
  scanf("%s",s[t].last_name);
  printf("Enter your unique roll no.\n");
  if (t==0)
  {
    scanf("%s",s[t].roll_no);
    printf("You have entered unique roll no.\n");
  }
  else
  {
    scanf("%s",s[t].roll_no);
    int flag=0;
    for(int i=0;i<t;i++)
    {
      if (strcmp(s[i].roll_no,s[t].roll_no)==0)
      {
        flag=1;
        break;
      }
    }
    if (flag==0)
    {
      printf("You have entered unique roll no.\n");
    }
    else
    {
      printf("You have entered duplicate roll no.\n");
      printf("Please re-enter the roll no:\n");
      scanf("%s",s[t].roll_no);
    }
  }
  printf("How many courses the student is enrolled in?\n");
  int n;
  scanf("%d",&n);
  for (int i=0;i<5;i++)
  {
    s[t].name[i]=0;
  }
  for (int i=0;i<n;i++)
  {
    printf("Enter the %d course:\n",i+1);
    char temp_course[10];
    scanf("%s",temp_course);
    switch(temp_course[0])
    {
      case '1':
        s[t].name[0]++;break;
      case '2':
        s[t].name[1]++;break;
      case '3':
        s[t].name[2]++;break;
      case '4':
        s[t].name[3]++;break;
      case '5':
        s[t].name[4]++;break;
    }
  }
  t++;
  printf("Data entered successfully\n");

}

void find_students_roll()
{
  printf("Enter a roll_no to find the details:\n");
  int flag=0;
  char temp[100];
  scanf("%s",temp);
  for (int i=0;i<t;i++)
  {
    if (strcmp(temp,s[i].roll_no)==0)
    {
      printf("%s %s %s ",s[i].first_name,s[i].last_name,s[i].roll_no);
      for (int j=0;j<5;j++)
      {
        if (s[i].name[j]!=0)
        {
          printf("%d01 ",j+1);
        }
      }
      printf("\n");
      flag=1;
      break;
    }
  }
  if (flag==0)
  {
    printf("No details found:\n");
  }
}

void find_students_course_id(void)
{
  char t_course[10];
  printf("Enter a course:\n");
  scanf("%s",t_course);
  switch(t_course[0])
  {
    case '1':
      for (int i=0;i<t;i++)
      {
        if (s[i].name[0]!=0)
        {
          print_data(i);
        }
      }
      break;
    case '2':
      for (int i=0;i<t;i++)
      {
        if (s[i].name[1]!=0)
        {
          print_data(i);
        }
      }
      break;
    case '3':
        for (int i=0;i<t;i++)
        {
          if (s[i].name[2]!=0)
          {
            print_data(i);
          }
        }
        break;
    case '4':
          for (int i=0;i<t;i++)
          {
            if (s[i].name[3]!=0)
            {
              print_data(i);
            }
          }
          break;
    case '5':
            for (int i=0;i<t;i++)
            {
              if (s[i].name[4]!=0)
              {
                print_data(i);
              }
            }
            break;
    }

}

void print_data(int position)
{
  int i=position;
  printf("%s %s %s ",s[i].first_name,s[i].last_name,s[i].roll_no);
  for (int j=0;j<5;j++)
  {
    if (s[i].name[j]!=0)
    {
      printf("%d01 ",j+1);
    }
  }
  printf("\n");
}

void summary(void)
{
  for (int i=0;i<5;i++)
  {
    int count = 0;
    for (int j=0;j<t;j++)
    {
      if (s[j].name[i]!=0)
      {
        count++;
      }
    }
    printf("No of students in course %d01 are %d.\n",i+1,count);
  }
}
