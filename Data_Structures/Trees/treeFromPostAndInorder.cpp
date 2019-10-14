#include<bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  struct Node *left, *right;
};

struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 

int search(int arr[], int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
} 

struct Node* build(int in[],int post[],int s,int e,int *p)
{
    if (s > e) 
        return NULL; 

    struct Node* node = newNode(post[*p]); 
    (*p)--; 

    if (s == e) 
        return node; 
    int i = search(in, s, e, node->data); 
    node->right = build(in, post, i + 1, e, p); 
    node->left = build(in, post, s, i - 1, p); 
  
    return node; 
}


struct Node* buildTree(int in[], int post[], int n)
{
	int p=n-1;
  	return build(in,post,0,n-1,&p);
}

void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 

int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
    int n= sizeof(in)/sizeof(in[0]);

    struct Node* root = buildTree(in, post, n); 
  
    preOrder(root); 
  
    return 0; 
}