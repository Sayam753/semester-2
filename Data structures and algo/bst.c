#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;
node *root=NULL;

int max_depth(node *temp)
{
  if (temp==NULL)
  {
    return 0;
  }
  int left_depth = max_depth(temp->left);
  int right_depth = max_depth(temp->right);
  if (left_depth>right_depth)
    return (left_depth+1);
  else
    return (right_depth+1);
}

int has_path_sum(node *temp,int value)
{
  if (temp==NULL)
  {
    return(value==0);
  }
  else
  {
    int inter = value-temp->data;
    return(has_path_sum(temp->left,inter)|| has_path_sum(temp->right,inter));
  }
}

int size(node *temp)
{
  if (temp == NULL)
  {
    return 0;
  }
  else return(size(temp->left)+1+size(temp->right));
}

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
  printf("%d ",root->data);
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

void delete()
{

}


int main()
{
  int choice;
  while(1)
  {
    printf("Enter the choice:\n1. To insert\n2. To inorder_print\n3. To preorder_print\n4. To postorder_print\n5. To find_min\n6. To find_max\n");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter the data: ");
        node *new_node = (node *)malloc(sizeof(node));
        scanf("%d",&new_node->data);
        new_node->right = NULL;
        new_node->left = NULL;
        if(root==NULL)
        {
          root = new_node;
        }
        else
        {
          insert(new_node,&root);
        }
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
      case 7:
        delete();
        break;
    }
  }
}

void free_tree(node* p)
{
    if ( !p )
        return;

    free_tree(p -> left);
    free_tree(p -> right);
    free(p);
}
