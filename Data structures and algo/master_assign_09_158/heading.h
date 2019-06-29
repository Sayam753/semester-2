struct student
{
  char name[20];
  int roll_no;
  float cgpa;
  int hackerRank;
  struct student *next;
};
typedef struct student student;
struct heap
{
  int hackerRank;
};

typedef struct heap heap;
extern student *head;
extern heap array_implementation[20];
extern int g_count;
extern int i;
extern int j;
extern int location;
extern student *temp;
extern student *prev;
extern int par;
extern int flag;
extern int temp_array[20];

void printStudentbyhackerrank(int hackerRank);
void deleteStudentByhackerrank(int hackerRank);
void addStudent();
void printAllStudent();
void updateStudentByRollNo();
void deleteStudentByRollNo();
void printStudentByRollNo();
void insert(int hackerRank);
void getToprankingStudent();
int percolateup(int location,int par);
void percolatedown(int nodeIndex);
void prettyprintBHeap(int index);
void buildingHeap();
void deleteMinimum();
