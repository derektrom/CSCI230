// C program for different tree traversals 
#include <stdio.h> 
#include <stdlib.h> 

/* Create node struct */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 

/* Reverse postorder */
void printReversePostorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	// first recur on right subtree 
	printReversePostorder(node->right); 

	// then recur on left subtree 
	printReversePostorder(node->left); 

	// now deal with the node 
	printf("%d ", node->data); 
} 

/* Print reverse inorder*/
void printReverseInorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	/* first recur on right child */
	printReverseInorder(node->right); 

	/* then print the data of node */
	printf("%d ", node->data); 

	/* now recur on left child */
	printReverseInorder(node->left); 
} 

/* Reverse preorder*/
void printReversePreorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	/* first print data of node */
	printf("%d ", node->data); 

	/* then recur on right sutree */
	printReversePreorder(node->right); 

	/* now recur on left subtree */
	printReversePreorder(node->left); 
}	 

/* Driver program to test above functions*/
int main() 
{ 
	struct node *root = newNode(1); 
	root->left			 = newNode(-2); 
	root->right		 = newNode(-3); 
	root->left->left	 = newNode(4); 
	root->left->right = newNode(5);
    root->left->right->left = newNode(-8);
    root->left->right->right = newNode(-9);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(10);
    root->right->right->right= newNode(11);
    root->right->right->right->left = newNode(-12);
    root->right->right->right->right = newNode(-13);
    root->right->right->right->right->left= newNode(14);
    

	printf("\nReverse Preorder traversal of binary tree is \n"); 
	printReversePreorder(root); 

	printf("\nReverse Inorder traversal of binary tree is \n"); 
	printReverseInorder(root); 

	printf("\nReverse Postorder traversal of binary tree is \n"); 
	printReversePostorder(root); 

	getchar(); 
	return 0; 
} 
