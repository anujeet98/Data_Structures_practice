#include<iostream>
#include<stdlib.h>
#include<queue> 
#include<stack>
using namespace std;


struct node
{
	int data;
	struct node *l;
	struct node *r;	
};



struct node *NewNode(int data)
{
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data=data;
	Node->l=NULL;
	Node->r=NULL;
	return Node;
}


struct node *insertBST(struct node *root, int data)
{
	if(root==NULL)
	{
		root=NewNode(data);
		return root;
	}
	else if(data<=root->data)
		root->l=insertBST(root->l,data);
	else
		root->r=insertBST(root->r,data);
	return root;
}


struct node *insertBTree(struct node *root, int data)
{
	if(root==NULL)
	{
		root=NewNode(data);
		return root;
	}
	queue<struct node*> q;
	q.push(root);

	while(!q.empty())
	{
		struct node *curr=q.front();
		q.pop();

		if(curr->l==NULL)
		{
			curr->l=NewNode(data);
			return root;
		}
		else
			q.push(curr->l);

		if(curr->r==NULL)
		{
			curr->r=NewNode(data);
			return root;
		}
		else
			q.push(curr->r);
	}
	return root;
}


struct node *deleteBTree(struct node *root, int key)
{
	if(root==NULL)
		return root;
	queue<struct node*> q;
	q.push(root);
	struct node *keyTOdel=NULL;
	struct node *curr;

	while(!q.empty())
	{
		curr=q.front();
		q.pop();

		if(curr->data==key)
			keyTOdel=curr;
		if(curr->l)
			q.push(curr->l);
		if(curr->r)
			q.push(curr->r);
	}

	if(keyTOdel!=NULL)
	{
		if(keyTOdel==curr)
			return NULL;
		else
		{
			keyTOdel->data=curr->data;
			free(curr);
/*			curr = curr->l;
			delete(curr);*/			
		}
	}
	return root;
}



void print_tree_inorder(struct node *root)
{
	if(root!=NULL)
	{
		print_tree_inorder(root->l);
		cout<<root->data<<" ";
		print_tree_inorder(root->r);
	}
}

void print_tree_preorder(struct node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		print_tree_preorder(root->l);
		print_tree_preorder(root->r);
	}
}

void print_tree_postorder(struct node *root)
{
	if(root!=NULL)
	{
		print_tree_postorder(root->l);
		print_tree_postorder(root->r);
		cout<<root->data<<" ";
	}
}

bool searchBST(struct node *root,int data)
{
	if(root==NULL)
		return false;
	else if(data==root->data)
		return true;
	else if(data<=root->data)
		return search(root->l,data);
	else
		return search(root->r,data);
}





void inorder_no_recusrion(struct node *root)
{
	stack<struct node*>st;
	st.push(root);
	struct node *curr=root;
	while(curr!=NULL || !st.empty())
	{
		while(curr!=NULL)
		{
			st.push(curr);
			curr=curr->l;			
		}

		curr=st.top();
		st.pop();

		cout<<curr->data<<" ";
		curr=curr->r;

	}
}


int main(void)
{
	//BST
	//create root
	struct node* root = NULL;

	//insert BST
/*	root = insertBST(root,15);
	root = insertBST(root,10);
	root = insertBST(root,20);
	root = insertBST(root,25);
	root = insertBST(root,8);
	root = insertBST(root,12);*/

	//insert BTree
	root = insertBTree(root,15);
	root = insertBTree(root,10);
	root = insertBTree(root,20);
	root = insertBTree(root,25);
	root = insertBTree(root,8);
	root = insertBTree(root,12);

	cout<<"inorder:";print_tree_inorder(root);
	cout<<"inorder:";inorder_no_recusrion(root);

	//delete node from BTree
	int ans;
	cout<<"want to delete?";
	cin>>ans;	
	int x;
	while(ans==1)
	{
		cout<<"\n delete no:";
		cin>>x;
		root=deleteBTree(root,x);
		cout<<"inorder:";print_tree_inorder(root);	
		cout<<"\ncont:";
		cin>>ans;
	}	




	//call print tree in,post,pre order DFS traversal
	cout<<"inorder:";print_tree_inorder(root);
	cout<<"\npreorder:";print_tree_preorder(root);
	cout<<"\npostorder:";print_tree_postorder(root);

	//search node BST
	ans=1;	
	while(ans==1)
	{
		cout<<"\nsearch no:";
		cin>>x;
		cout<<searchBST(root,x)<<"\n";
		cout<<"cont:";
		cin>>ans;
	}



}