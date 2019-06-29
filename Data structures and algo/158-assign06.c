#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int length_sec_a=0;
int length_sec_b=0;
int length_masterlist=0;

struct student
{
  char name[20];
  int roll_no;
  struct student *next_student;
};

typedef struct student Student;
Student *sec_a=NULL;
Student *sec_b=NULL;
Student *masterlist=NULL;

void add(Student *student,Student *sec)
{
  Student *temp;
  if (sec == sec_a)
  {
    temp = sec_a;
  }
  else if (sec==sec_b)
  {
    temp = sec_b;
  }
  while(temp->next_student!=NULL)
  {
    temp = temp->next_student;
  }
  temp->next_student = student;
}

void create(Student *sec)
{
  Student *new_student = (Student *)malloc(sizeof(Student));
  printf("Enter the details of student: ");
  scanf("%s %d",new_student->name,&(new_student->roll_no));
  new_student->next_student=NULL;
  add(new_student,sec);
}

void print(Student *s)
{
  printf("\nName is %s and rollno is %d.\n",s->name,s->roll_no);
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

void update(int i,Student *nstudent,Student *head)
{
  if (head==sec_a)
  {
    if (i<=0 && i>length_sec_a)
    {
      printf("Wrong index\n");
      return;
    }
  }
  if (head==sec_b)
  {
    if (i<=0 && i>length_sec_b)
    {
      printf("Wrong index\n");
      return;
    }
  }
  if (head==masterlist)
  {
    if (i<=0 && i>length_masterlist)
    {
      printf("Wrong index\n");
      return;
    }
  }
  Student *temp;
  if (head == sec_a)
    temp = sec_a;
  else if (head==sec_b)
    temp = sec_b;
  else
    temp = masterlist;
  for (int j=1;j<=i;j++)
  {
    temp = temp->next_student;
  }
  strcpy(temp->name,nstudent->name);
  temp->roll_no = nstudent->roll_no;
}

void insert(int i,Student *student,Student *head)
{
  if (head==sec_a)
  {
    if (i<=0 && i>length_sec_a+1)
    {
      printf("Wrong index\n");
      return;
    }
  }
  if (head==sec_b)
  {
    if (i<=0 && i>length_sec_b+1)
    {
      printf("Wrong index\n");
      return;
    }
  }
  if (i==1)
  {
    if (head==NULL)
      head = student;
    else
    {
      student->next_student = head;
      head = student;
    }
  }
  else
  {
    Student *temp;
    if (head == sec_a)
      temp = sec_a;
    else if (head==sec_b)
      temp = sec_b;
    else
      temp = masterlist;
    for (int j=1;j<i-1;j++)
    {
      temp = temp->next_student;
    }
    student->next_student=temp->next_student;
    temp->next_student= student;
  }
  if (head==sec_a)
  {
    length_sec_a++;
  }
  if (head==sec_b)
  {
    length_sec_b++;
  }
}

void delete(int i,Student *head)
{
  if (head==sec_a)
  {
    if (i<=0 && i>length_sec_a)
    {
      printf("Wrong index\n");
      return;
    }
  }
  if (head==sec_b)
  {
    if (i<=0 && i>length_sec_b)
    {
      printf("Wrong index\n");
      return;
    }
  }
  Student *temp;
  if (head == sec_a)
    temp = sec_a;
  else if (head==sec_b)
    temp = sec_b;
  else
    temp = masterlist;
  if (i == 1)
  {
      head = temp->next_student;
      free(temp);
      return;
  }
  for (int j=1;j<i-1;j++)
       temp = temp->next_student;
  Student *next = temp->next_student->next_student;
  free(temp->next_student);
  temp->next_student = next;
  if (head==sec_a)
  {
    length_sec_a--;
  }
  if (head==sec_b)
  {
    length_sec_b--;
  }
}

Student* get(int i,Student *head)
{
  Student* not_exist = NULL;
  if (head==sec_a)
  {
    if (i<=0 && i>length_sec_a)
    {
      printf("Wrong index\n");
      return not_exist;
    }
  }
  if (head==sec_b)
  {
    if (i<=0 && i>length_sec_b)
    {
      printf("Wrong index\n");
      return not_exist;
    }
  }
  if (head==masterlist)
  {
    if (i<=0 && i>length_masterlist)
    {
      printf("Wrong index\n");
      return not_exist;
    }
  }
  Student *temp1=NULL;
  Student *temp=head;
  for(int j=1;;j++)
  {
    if (j==i)
    {
      return(temp);
    }
    temp = temp->next_student;
  }
  return temp1;
}

Student* Merge(Student* a, Student* b);
void partition(Student* source,Student** start_half, Student** mid_half);

void mergeSort(Student** sec)
{
  Student* head = *sec;
  Student* a;
  Student* b;
  if ((head == NULL) || (head->next_student == NULL))
  {
  	return;
  }
  partition(head, &a, &b);
  mergeSort(&a);
  mergeSort(&b);
  *sec = Merge(a, b);
}

Student* Merge(Student* a, Student* b)
{
  Student* ans = NULL;

  if (a == NULL)
  	return(b);
  else if (b==NULL)
  	return(a);

  if (a->roll_no <= b->roll_no)
  {
  	ans = a;
  	ans->next_student = Merge(a->next_student, b);
  }
  else
  {
  	ans = b;
  	ans->next_student = Merge(a, b->next_student);
  }
  return(ans);
}

void partition(Student* source,Student** start_half, Student** mid_half)
{
		Student* fast;
		Student* slow;
  	slow = source;
  	fast = source->next_student;
  	while (fast != NULL)
  	{
    	fast = fast->next_student;
    	if (fast != NULL)
    	{
    		slow = slow->next_student;
    		fast = fast->next_student;
    	}
	  }

	*start_half = source;
	*mid_half = slow->next_student;
	slow->next_student = NULL;
}

int main()
{
  int flag=1;
  int choice,choice_of_section,position;
  while(flag!=0)
  {
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
        printf("Creating Student. Enter 1 for Sec A, 2 for Sec B: ");
        scanf("%d",&choice_of_section);
        fflush(stdin);
        if (choice_of_section==1)
        {
          if (sec_a==NULL)
          {
            Student *new_student = (Student *)malloc(sizeof(Student));
            printf("Enter the details of student: ");
            scanf("%s %d",new_student->name,&(new_student->roll_no));
            new_student->next_student=NULL;
            sec_a = new_student;
          }
          else
          {
            create(sec_a);
          }
          length_sec_a++;
        }
        if (choice_of_section==2)
        {
          if(sec_b==NULL)
          {
            Student *new_student = (Student *)malloc(sizeof(Student));
            printf("Enter the details of student: ");
            scanf("%s %d",new_student->name,&(new_student->roll_no));
            new_student->next_student=NULL;
            sec_b = new_student;
          }
          else
          {
            create(sec_b);
          }
          length_sec_b++;

        }
        break;
      case 2:
        printf("Inserting Student. Enter 1 for Sec A, 2 for Sec B: ");
        scanf("%d",&choice_of_section);
        printf("Enter the position: ");
        scanf("%d",&position);
        Student *new_student = (Student *)malloc(sizeof(Student));
        printf("Enter the details of student: ");
        scanf("%s %d",new_student->name,&(new_student->roll_no));
        new_student->next_student=NULL;
        if (choice_of_section==1)
        {
          insert(position,new_student,sec_a);
        }
        else if (choice_of_section==2)
        {
          insert(position,new_student,sec_b);
        }
        break;
      case 3:
        printf("Deleting Student. Enter 1 for Sec A, 2 for Sec B and 3 for Master: ");
        scanf("%d",&choice_of_section);
        printf("Enter the position: ");
        scanf("%d",&position);
        if (choice_of_section==1)
        {
          delete(position,sec_a);
        }
        else if (choice_of_section==2)
        {
          delete(position,sec_b);
        }
        break;
      case 4:
        masterlist = Merge(sec_a,sec_b);
        break;
      case 5:
        printf("Creating Student. Enter 1 for Sec A, 2 for Sec B and 3 for Master: ");
        scanf("%d",&choice_of_section);
        if (choice_of_section==1)
          mergeSort(&sec_a);
        else if (choice_of_section==2)
          mergeSort(&sec_b);
        else if (choice_of_section==3)
          mergeSort(&masterlist);
        break;
      case 6:
      printf("Print Student. Enter 1 for Sec A, 2 for Sec B and 3 for Master: ");
      scanf("%d",&choice_of_section);
      fflush(stdin);
      if (choice_of_section==1)
        print_all(sec_a);
      else if (choice_of_section==2)
        print_all(sec_b);
      else if (choice_of_section==3)
        print_all(masterlist);
      break;
    }
    fflush(stdin);
    printf("Enter flag:\n");
    scanf("%d",&flag);
    fflush(stdin);
  }
}
