#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

typedef struct node node;
node *root=NULL;

void insert(node *new_node,node **root)
{
  if ((*root)->left==NULL && (*root)->data > new_node->data)
  {
    (*root)->left = new_node;
    return;
  }
  else if ((*root)->right==NULL && (*root)->data < new_node->data)
  {
    (*root)->right = new_node;
    return;
  }
  else if ((*root)->left!=NULL && (*root)->data > new_node->data)
  {
    insert(new_node,&((*root)->left));
  }
  else if ((*root)->right!=NULL && (*root)->data < new_node->data)
  {
    insert(new_node,&((*root)->right));
  }
}

void inorder_print(node *root)
{
  if (root==NULL)
  {
    return;
  }
  inorder_print(root->left);
  printf("%d %p %p %p\n",root->data,root,root->left,root->right);
  //printf("%d ",root->data);
  inorder_print(root->right);
}

void preorder_print(node *root)
{
  if (root==NULL)
  {
    return;
  }
  printf("%d ",root->data);
  preorder_print(root->left);
  preorder_print(root->right);

}

void postorder_print(node *root)
{
  if (root==NULL)
  {
    return;
  }
  postorder_print(root->left);
  postorder_print(root->right);
  printf("%d ",root->data);
}

void find_max(node *root)
{
  if (root->right==NULL)
  {
    printf("Max is %d\n",root->data);
    return;
  }
  find_max(root->right);
}

void find_min(node *root)
{
  if (root->left==NULL)
  {
    printf("Min is %d\n",root->data);
    return;
  }
  find_min(root->left);
}

void find_element(node *root,int element)
{
  
}

void create(int a[],int low,int high)
{
  if (low>high)
  {
    return;
  }
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = a[(low+high)/2];
  new_node->right = NULL;
  new_node->left = NULL;
  insert(new_node,&root);
  create(a,(low+high)/2+1,high);
  create(a,low,(low+high)/2-1);
}

int main()
{
  printf("Enter the no of elements: ");
  int n;
  scanf("%d",&n);
  int a[n];
  for (int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  mergeSort(a,0,n-1);
  int low = 0,high = n-1,mid = (low+high)/2;
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = a[mid];
  new_node->right = NULL;
  new_node->left = NULL;
  root = new_node;
  create(a,0,(n-1)/2-1);
  create(a,(n-1)/2+1,n-1);
  int choice;
  while(1)
  {
    printf("Enter the choice:\n1. To find_element\n2. To inorder_print\n3. To preorder_print\n4. To postorder_print\n5. To find_min\n6. To find_max\n");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter the element: ");
        int element;
        scanf("%d",&element);
        find_element(root,element);
        break;
      case 2:
        inorder_print(root);
        printf("\n");
        break;
      case 3:
        preorder_print(root);
        printf("\n");
        break;
      case 4:
        postorder_print(root);
        printf("\n");
        break;
      case 5:
        find_min(root);
        break;
      case 6:
        find_max(root);
        break;
    }
  }
}
