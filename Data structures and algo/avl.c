#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
	int ht;
}node;

void inorder(node *T);
node * Insert(node *T,int x);
int height(node *T);
node * Delete(node *T,int x);
node * rotateright(node *x);
node * rotateleft(node *x);
void preorder(node *T);
node * RR(node *T);
node * LL(node *T);
node * LR(node *T);
node * RL(node *T);



node * Delete(node *T,int x)
{
	node *p;
	if(T==NULL)
	{
		return NULL;
	}
	else
		if(x > T->data)		// Insert in right subtree
		{
			T->right=Delete(T->right,x);
			if(height(T->left)-height(T->right)==2)
			{
        if(height(T->left->left)-height(T->left->right)>=0)
  					T=LL(T);
  				else
  					T=LR(T);
      }
		}
		else
			if(x<T->data)
			{
				T->left=Delete(T->left,x);
				if(height(T->right)-height(T->left)==2)	//Rebalance during windup
	       {
           if(height(T->right->left)-height(T->right->right)<=0)
						T=RR(T);
					else
						T=RL(T);
          }
			}
			else
			{
				//data to be deleted is found
				if(T->right!=NULL)
				{	//delete its inorder succesor
					p=T->right;

					while(p->left!= NULL)
						p=p->left;

					T->data=p->data;
					T->right=Delete(T->right,p->data);

					if(height(T->left)-height(T->right)==2)//Rebalance during windup
					{
            if(height(T->left->left)-height(T->left->right)>=0)
  							T=LL(T);
  						else
  							T=LR(T);
          }
				}
				else
					return(T->left);
			}
	T->ht=height(T);
	return(T);
}


void preorder(node *T)
{
	if(T!=NULL)
	{
		printf("%d(Bf=%d)",T->data,BF(T));
		preorder(T->left);
		preorder(T->right);
	}
}

void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d(Bf=%d)",T->data,BF(T));
		inorder(T->right);
	}
}


int main()
{
	node *root=NULL;
	int x,n,i,op;

	while(1)
	{
		printf("1)Insert:\t2)Delete\t3)print");
		scanf("%d",&op);
		switch(op)
		{

			case 1: printf("\nEnter a data:");
					scanf("%d",&x);
					root=Insert(root,x);
					break;

			case 2: printf("\nEnter a data:");
					scanf("%d",&x);
					root=Delete(root,x);
					break;

			case 3: printf("\nPreorder sequence:\n");
					preorder(root);
					printf("\n\nInorder sequence:\n");
					inorder(root);
					printf("\n");
					break;
		}
	}

	return 0;
}
