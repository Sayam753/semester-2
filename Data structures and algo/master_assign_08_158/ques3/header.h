typedef struct student student;
extern student *start;
struct student
{
  int rollno;
  char name[20];
  float cgpa;
  struct student *next;
};
void add();
void print(student *node);
void printfrom(student *node);
void print_all();
student* find_roll_no(int roll);
void delete_by_roll(int roll);
