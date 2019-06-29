#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char first_name[20];
    char last_name[20];
    char roll_no[15];
    float cgpa;
    struct student *next_student;
};

struct student *first_student=NULL;

void join(struct student *f1, struct student *f2)
{
    f1->next_student = f2;
}

void create(struct student *s1)
{
    struct student *temp;
    scanf("%s %s %s %f",s1->first_name,s1->last_name,s1->roll_no,&s1->cgpa);
    if (first_student==NULL)
    {
        first_student = s1;
        first_student->next_student = NULL;
    }
    else
    {
        temp = first_student;
        while(temp->next_student!=NULL)
        {
            temp = temp->next_student;
        }
        join(temp,s1);
    }
}

void display(struct student *head)
{
    if (head==NULL)
    {
        return;
    }
    else
    {
        printf("\nFirst Name is %s.\n",head->first_name);
        printf("Last Name is %s.\n",head->last_name);
        printf("Roll No is %s.\n",head->roll_no);
        printf("CGPA is %f.\n\n",head->cgpa);
    }
    display(head->next_student);
}

int main()
{
    int n;
    printf("How many students?\n");
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        struct student *s1 = (struct student *)malloc(sizeof(struct student));
        create(s1);
    }
    display(first_student);
}
