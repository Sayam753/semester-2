#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct trie_node
{
  int is_end;
  struct trie_node *children_array[26];
};

typedef struct trie_node trie_node;
trie_node *head_of_trie;

struct avl_node
{
    int data;
    int ht;
    struct avl_node* left;
    struct avl_node* right;
};

typedef struct avl_node avl_node;
int height(avl_node *travel);

int BF(avl_node *travel)
{
	int lh,rh;
	if(travel==NULL)
		return(0);

	if(travel->left==NULL)
		lh=0;
	else
		lh=1+travel->left->ht;

	if(travel->right==NULL)
		rh=0;
	else
		rh=1+travel->right->ht;

	return(lh-rh);
}


avl_node * rotateright(avl_node *down)
{
	avl_node *up;
	up=down->left;
	down->left=up->right;
	up->right=down;
	down->ht=height(down);
	up->ht=height(up);
	return(up);
}

avl_node * rotateleft(avl_node *down)
{
	avl_node *up;
	up=down->right;
	down->right=up->left;
	up->left=down;
	down->ht=height(down);
	up->ht=height(up);

	return(up);
}


avl_node * LR(avl_node *travel)
{
	travel->left=rotateleft(travel->left);
	travel=rotateright(travel);

	return(travel);
}

avl_node * RL(avl_node *travel)
{
	travel->right=rotateright(travel->right);
	travel=rotateleft(travel);
	return(travel);
}

int height(avl_node *travel)
{
	int lh,rh;
	if(travel==NULL)
		return(0);

	if(travel->left==NULL)
		lh=0;
	else
		lh=1+travel->left->ht;

	if(travel->right==NULL)
		rh=0;
	else
		rh=1+travel->right->ht;

	if(lh>rh)
		return(lh);

	return(rh);
}

avl_node * Insert_in_avl(avl_node *travel,int value)
{
	if(travel==NULL)
	{
		travel=(avl_node*)malloc(sizeof(avl_node));
		travel->data=value;
		travel->left=NULL;
		travel->right=NULL;
	}
	else
		if(value > travel->data)
		{
			travel->right=Insert_in_avl(travel->right,value);
      printf("BF is %d for %d.\n",BF(travel),travel->data);
			if(BF(travel)==-2)
			{
        if(value>travel->right->data)
        {
          printf("Pursing left on %d.\n",travel->data);
    			travel=rotateleft(travel);
        }
  			else
        {
          printf("Pursing RL on %d.\n",travel->data);
					travel=RL(travel);
        }
      }
		}
		else
			if(value<travel->data)
			{
				travel->left=Insert_in_avl(travel->left,value);
        printf("BF is %d for %d.\n",BF(travel),travel->data);
				if(BF(travel)==2)
				{
          if(value < travel->left->data)
          {
            printf("Pursing right on %d.\n",travel->data);
            travel=rotateright(travel);
          }
				  else
          {
            printf("Pursing LR on %d.\n",travel->data);
            travel=LR(travel);
          }
        }
			}
		travel->ht=height(travel);
    printf("Height of %d is %d.\n",travel->data,travel->ht);
		return(travel);
}

void inorder_print(avl_node *avl_root)
{
  if (avl_root==NULL)
  {
    return;
  }
  inorder_print(avl_root->left);
  printf("%d ",avl_root->data);
  inorder_print(avl_root->right);
}

void preorder_print(avl_node *avl_root)
{
  if (avl_root==NULL)
  {
    return;
  }
  printf("%d ",avl_root->data);
  preorder_print(avl_root->left);
  preorder_print(avl_root->right);
}

int Search_in_avl(avl_node* avl_node, int target) {
  if (avl_node == NULL)
  {
    return(0);
  }
  else
  {
    if (target == avl_node->data) return(1);
    else
    {
      if (target < avl_node->data)
      {
        return(Search_in_avl(avl_node->left, target));
      }
      else
      {
        return(Search_in_avl(avl_node->right, target));
      }
    }
  }
}

avl_node * Delete_in_avl(avl_node *travel,int value)
{
	avl_node *temp;

	if(travel==NULL)
	{
		return NULL;
	}
	else
		if(value > travel->data)
		{
			travel->right=Delete_in_avl(travel->right,value);
			if(BF(travel)==2)
			{
        if(BF(travel->left)>=0)
  					travel=rotateright(travel);
  			else
  					travel=LR(travel);
      }
		}
		else
			if(value<travel->data)
			{
				travel->left=Delete_in_avl(travel->left,value);
				if(BF(travel)==-2)
				{
          if(BF(travel->right)<=0)
  						travel=rotateleft(travel);
  				else
  						travel=RL(travel);
        }
			}
			else
			{
				if(travel->right!=NULL)
				{
					temp=travel->right;

					while(temp->left!= NULL)
						temp=temp->left;

					travel->data=temp->data;
					travel->right=Delete_in_avl(travel->right,temp->data);

					if(BF(travel)==2)
					{
            if(BF(travel->left)>=0)
  							travel=rotateright(travel);
  					else
  							travel=LR(travel);
          }
				}
				else
					return(travel->left);
			}
	travel->ht=height(travel);
	return(travel);
}

trie_node *create_empty_trie_node()
{
  trie_node *new_trie_node = (trie_node *)malloc(sizeof(trie_node));
  for (int i=0;i<26;i++)
    new_trie_node->children_array[i] = NULL;
  new_trie_node->is_end = 0;
  return new_trie_node;
}

void Insert_in_trie(char s[],int length)
{
  trie_node *temp=head_of_trie;
  for (int i=0;i<length;i++)
  {
    if (temp->children_array[s[i]-'a']==NULL)
    {
      printf("Creating new_level for '%c'.\n",s[i]);
      trie_node *new_trie_node = create_empty_trie_node();
      temp->children_array[s[i]-'a'] = new_trie_node;
      temp = new_trie_node;
    }
    else
    {
      printf("Character skipped is '%c'.\n",s[i]);
      temp = temp->children_array[s[i]-'a'];
    }
  }
  if(temp->is_end==1)
  {
    printf("Word already present!!\n");
    return;
  }
  printf("Setting is_end for '%c'.\n",s[length-1]);
  temp->is_end=1;
}

int Search_in_trie(char s[],int length)
{
  int flag=1;
  trie_node *temp = head_of_trie;
  for(int i=0;i<length;i++)
  {
    if (temp->children_array[s[i]-'a']==NULL)
    {
      flag=0;
      break;
    }
    temp = temp->children_array[s[i]-'a'];
  }
  if (flag==1 && temp->is_end==1)
  {
    return 1;
  }
  return 0;
}

void Delete_in_trie(char s[],int length)
{
  if (!Search_in_trie(s,length))
  {
    printf("Word not present!!\n");
    return;
  }
  else
  {
    int location=-1,flag=0;
    trie_node *temp = head_of_trie,*ahead_of_trie=head_of_trie,*storing_ahead_of_trie;
    for (int i=0;i<length;i++)
    {
      if (i!=length-1)
      {
        flag=0;
        for (int j=0;j<26;j++)
        {
          if ((s[i+1]-'a')!=j)
          {
            if ((temp->children_array[s[i]-'a']->children_array[j])!=NULL)
            {
              flag=1;
              break;
            }
          }
        }
        if(temp->children_array[s[i]-'a']->is_end==1 || flag==1)
        {
          ahead_of_trie=temp->children_array[s[i]-'a'];
          location=i;
        }
      }
      temp = temp->children_array[s[i]-'a'];
    }
    for (int i=0;i<26;i++)
    {
      if (temp->children_array[i]!=NULL)
      {
        temp->is_end = 0;
        return;
      }
    }
    storing_ahead_of_trie = ahead_of_trie;
    for (int i=location+1;i<length;i++)
    {
      printf("Deleting level for '%c'.\n",s[i]);
      temp = ahead_of_trie->children_array[s[i]-'a'];
      free(ahead_of_trie->children_array[s[i]-'a']);
      ahead_of_trie=temp;
    }
    storing_ahead_of_trie->children_array[s[location+1]-'a']=NULL;
    return;
  }
}

int main()
{
  avl_node* avl_root = NULL;
  head_of_trie = (trie_node *)malloc(sizeof(trie_node));
  for (int i=0;i<26;i++)
  {
    head_of_trie->children_array[i] = NULL;
  }
  head_of_trie->is_end = 0;
  while(1)
  {
    int choice,data;
    char string[100];
    printf("Enter\n1. Insert_in_trie\n2. Search_in_trie\n3. Delete_in_trie\n4. Insert_in_avl\n5. Delete_in_avl\n6. Search_in_avl\n7. Print avl\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter a string to Insert_in_trie: ");
        scanf("%s",string);
        int length = strlen(string);
        for (int i=0;i<length;i++)
        {
          if (string[i]>=65 && string[i]<=90)
          {
            string[i] = string[i]+32;
          }
        }
        Insert_in_trie(string,strlen(string));
        break;

      case 2:
        printf("Enter a string to Search_in_trie: ");
        scanf("%s",string);
        if (Search_in_trie(string,strlen(string)))
          printf("Word present!!\n");
        else
          printf("Word not present!!\n");
        break;

      case 3:
        printf("Enter a string to Delete_in_trie: ");
        scanf("%s",string);
        Delete_in_trie(string,strlen(string));
        break;
      case 4:
        printf("Enter data to Insert_in_avl: ");
        scanf("%d",&data);
        avl_root = Insert_in_avl(avl_root,data);
        break;

      case 5:
        printf("Enter data to Delete_in_avl: ");
        scanf("%d",&data);
        if (Search_in_avl(avl_root,data))
          avl_root = Delete_in_avl(avl_root,data);
        else
          printf("Data not present!!\n");
        break;

      case 6:
        printf("Enter data to Search_in_avl: ");
        scanf("%d",&data);
        if (Search_in_avl(avl_root,data))
          printf("Data present!!\n");
        else
          printf("Data not present!!\n");
        break;

      case 7:
        printf("Inorder traversal is:\n");
        inorder_print(avl_root);
        printf("\nPre-order traversal is:\n");
        preorder_print(avl_root);
        printf("\n");
        break;
    }
  }
}
