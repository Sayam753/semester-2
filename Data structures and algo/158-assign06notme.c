#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef MAX_STUDENTS
#define MAX_STUDENTS 50
#endif

struct student
{
  char name[20];
  int roll_no;
  float cgpa;
  struct student *next_student;
};
typedef struct student Student;
int no_of_nodes=0;
Student *start=NULL; // head of linked list
Student *g_student_index[MAX_STUDENTS];

Student* create(void)
{
  Student *new_student = (Student *)malloc(sizeof(Student));
  printf("Enter the details of student: ");
  scanf("%s %d %f",new_student->name,&(new_student->roll_no),&(new_student->cgpa));
  new_student->next_student=NULL;
  return(new_student);
}

void print(Student *s)
{
  printf("\nName of student is %s. ",s->name);
  printf("Roll No is %d and  cgpa is %f.\n",s->roll_no,s->cgpa);
  fflush(stdin);
}

void print_from(Student *s)
{
  if (s==NULL)
  {
    return;
  }
  else
  {
    print(s);
    return print_from(s->next_student);
  }
}

void print_all(Student *start)
{
  print_from(start);
}

void add(Student *student)
{
  Student *temp;
  temp = start;
  while(temp->next_student!=NULL)
  {
    temp = temp->next_student;
  }
  temp->next_student = student;
}

void update(int i, Student *nstudent)
{
  Student *temp;
  temp = start;
  for (int j=1;j<=i;j++)
  {
    temp = temp->next_student;
  }
  strcpy(temp->name,nstudent->name);
  temp->roll_no = nstudent->roll_no;
  temp->cgpa = nstudent->cgpa;
}

void insert(int i,Student *student)
{
  Student *temp = start;
  if (i==1)
  {
    if (start==NULL)
      start = student;
    else
    {
      student->next_student = start;
      start = student;
    }
  }
  else
  {
    for (int j=1;j<i-1;j++)
    {
      temp = temp->next_student;
    }
    student->next_student=temp->next_student;
    temp->next_student= student;

  }
  no_of_nodes++;
}

void deletion(int i)
{
  Student* temp = start;
  if (i == 1)
  {
      start = temp->next_student;
      free(temp);
      return;
  }
  for (int j=1;j<i-1;j++)
       temp = temp->next_student;
  Student *next = temp->next_student->next_student;
  free(temp->next_student);
  temp->next_student = next;
  no_of_nodes--;
}

Student* get(int i)
{
  Student *temp1=NULL;
  Student *temp=start;
  for(int j=1;j<=no_of_nodes;j++)
  {
    if (j==i)
    {
      return(temp);
    }
    temp = temp->next_student;
  }
  return temp1;
}

void add_to_index()
{
  printf("hello\n");
}

void delete_from_index()
{
  printf("hello\n");
}

void update_index()
{
  for(int i=0;i<MAX_STUDENTS;i++)
  {
    for (int j=i+1;MAX_STUDENTS;i++)
    {
      if (g_student_index[i]->roll_no>g_student_index[j]->roll_no)
      {
        Student *temp = g_student_index[i];
        g_student_index[i] = g_student_index[j];
        g_student_index[j] = temp;
      }
    }
  }
}

void search(int rollno)
{
  int flag=0,low=0,high = MAX_STUDENTS;
  int mid = (low+high)/2;
  while(low<high)
  {
    if (g_student_index[mid]->roll_no==rollno)
    {
      flag=1;
      print(g_student_index[mid]);
      return;
    }
    else if (g_student_index[mid]->roll_no>rollno)
    {
      high = mid-1;
    }
    else
    {
      low = mid+1;
    }
    mid = (low+high)/2;
  }
  if(flag==0)
  {
    printf("Roll no not found.\n");
  }
}

void print_by_index()
{
  for(int i=0;g_student_index[i]->next_student!=NULL;i++)
  {
    print(g_student_index[i]);
  }
}

int main()
{
  int choice,flag=1,position;
  Student *new_student,*get_student;
  while(flag!=0)
  {
    printf("Enter your choice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        new_student = create();
        insert(no_of_nodes,new_student);
        break;
      case 2:
        print_all(start);
        break;
      case 3:
        scanf("%d",&position);
        new_student = create();
        update(position,new_student);
        break;
      case 4:
        printf("Enter position\n");
        scanf("%d",&position);
        new_student = create();
        insert(position,new_student);
        break;
      case 5:
        printf("Enter position\n");
        scanf("%d",&position);
        deletion(position);
        break;
      case 6:
        update_index();
        break;
      case 7:
        printf("Enter position\n");
        scanf("%d",&position);
        search(position);
        break;
      case 8:
        print_by_index();
        break;
  fflush(stdin);
  printf("Enter 1 to continue the program else press 0: ");
  scanf("%d",&flag);
  }
}
