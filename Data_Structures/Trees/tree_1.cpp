/*
 * Trees 
 */

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

struct Node* insertBST(struct Node* root,int key)
{
    if (root == NULL)
    {
        struct Node *temp =  new struct Node(key);
        temp->data = key;
        temp->left = temp->right = NULL;

        return temp;
    }

    if (key < root->data)
        root->left = insertBST(root->left, key);
    else if (key > root->data)
        root->right = insertBST(root->right, key);

    return root;
}


//Recursive Inorder Printing of A tree
void printInOrder(struct Node* root)
{
    if(!root)
        return;
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}


//Recursive PostOrder printing of a tree
void printPostOrder(struct Node* root)
{
    if(!root)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}


//Recursive PreOrder printing of a tree
void printPreOrder(struct Node* root)
{
    if(!root)
        return;
    cout<<root->data;
    printPreOrder(root->left);
    printPreOrder(root->right);
    cout<<root->data<<" ";
}


//Iterative PostOrder printing of a tree
void printPostOrderIterative(struct Node* root)
{
    if(!root)
        return;
    stack<struct Node* > s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        struct Node* temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        struct Node* temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
    
}


//Iteretive InOrder printing of a tree
void printInOrderIterative(struct Node* root)
{
    if(!root)
        return;
    stack<struct Node*> st;
    struct Node* temp = root;
    while (temp!=NULL || !st.empty())
    {
        while (temp)
        {
            st.push(temp);
            temp=temp->left;
        }
        temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    
}

//Iterative PostOrder printing of a tree
void printPreOrderIterative(struct Node *root)
{
    if(!root)
        return;
    stack<struct Node*> st;
    st.push(root);
    while(!st.empty())
    {
        struct Node* temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);

    }
}

void fillArray(struct Node *root,int *a,int len,int *max)
{
    if(!root)
        return;
    if(!root->right && !root->left)
    {
        a[len]=root->data;
        (*max)++;
        for(int i=0;i<=len;i++)
        {
        printf("%d ",a[i]);
        }
        printf("%d\n",len);
        return;
    }
    a[len]=root->data;
    fillArray(root->left,a,len+1,max);
    fillArray(root->right,a,len+1,max);
}

//Printing All Paths of A Tree
void printAllPaths(struct Node* root) 
{
    if(!root)
        return;
    int a[100];
    int max=0;
    fillArray(root,a,0,&max);
    printf("%d",max);
}

//Find Hieght of a tree
int getHeight(struct Node* root)
{
    if(!root)
        return -1;
    int l=getHeight(root->left);
    int r=getHeight(root->right);
    return (l>r) ? l+1 : r+1; 
}


//Level Order printing of a tree
void printLevelOrder(struct Node * root)
{
    if(!root)
        return;
    queue<struct Node*> q;
    //q.push(root);
    while (root)
    {
        if(root->left)
        {
            q.push(root->left);
        }
        if(root->right)
        {
            q.push(root->right);
        }
        cout<<root->data<<" ";
        root = q.front();
        q.pop();
    }
    
}


//Reverse Level Order printing of a tree
void printReverseLevelOrder(struct Node* root)
{  
    if(!root)
        return;
    queue <struct Node*> q;
    stack <struct Node*> s;

    q.push(root);

    while (!q.empty())
    {
        struct Node* temp=q.front();
        q.pop();
        s.push(temp);

        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
    }

    while (!s.empty())
    {
        struct Node* temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
    }
}


//Prints The Tree Spirally
void printSpiral(struct Node* root)
{
    if(!root)
        return ;

    int oddLevel=true;
    stack<struct Node*> s;
    queue<struct Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            struct Node* temp = q.front();
            q.pop();

            if(oddLevel)
                s.push(temp);
            else
            {
                cout<<temp->data<<" ";
            }

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }

        if(oddLevel)
        {
            while(!s.empty())
            {
                struct Node* temp=s.top();
                s.pop();
                cout<<temp->data<<" ";
            }
        }

        oddLevel = (oddLevel == 1)?0 : 1;
    }
}

//Utility Function to fill The Map used in Vertical Order,Top view,bottom view.
void levelOrder(struct Node* root,int d,  map<int, vector<int>> &m)
{
    if(!root)
        return;
    m[d].push_back(root->data);
    levelOrder(root->left,d-1,m);
    levelOrder(root->right,d+1,m);
}


//Prints Vertical Order Of A tree
void printVerticalOrder(struct Node* root)
{
    map <int,vector<int>> m; 
    int hd = 0; 
    levelOrder(root,hd,m);
    for (auto it = m.begin(); it!=m.end(); it++)
    {
        cout<<it->first<<"--->";
        for (int i = 0; i < it->second.size(); i++)
        {
            cout<<it->second[i];
            if(i!=it->second.size()-1)
                cout<<",";
        }
        cout<<endl;
    }
}


//Prints Top View of A Tree
void printTopView(struct Node* root)
{
    map <int,vector<int>> m; 
    int hd = 0; 
    levelOrder(root,hd,m);
    for (auto it = m.begin(); it!=m.end(); it++)
    {
        cout<<it->second[0]<<" ";
    }
}


// Prints Bottom View of a Tree
void printBottomView(struct Node* root)
{
    map <int,vector<int>> m; 
    int hd = 0; 
    levelOrder(root,hd,m);
    for (auto it = m.begin(); it!=m.end(); it++)
    {
        cout<<it->second[it->second.size()-1]<<" ";
    }
}


//Converts Tree to a Doubly Linked List
void TreeToDLL(struct Node* root,struct Node** head)
{
    if(!root)
        return ;
    TreeToDLL(root->right,head);
    root->right=*head;

    if(*head!=NULL)
    {
        (*head)->left=root;
    }
    *head = root;

    TreeToDLL(root->left,head);
}

//Prints The DLL
void printList(struct Node* head)
{
    struct Node* temp=head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->right;
        /* code */
    }
}

void deleteTree(struct Node* root)
{
    if(!root)
        return ;
    deleteTree(root->left);
    deleteTree(root->right);

    free(root);
}

//Utility Function
int isBST(struct Node* root,int min,int max)
{
  if(!root)
  {
    return 1;
  }
  if(root->data<min || root->data>max)
  {
	return 0;
  }    
  return isBST(root->left,min,root->data)&&isBST(root->right,root->data,max);
}


//Function For Checking Given BT is a BST or not
int isBinarySearchTree(struct Node* root)
{
	if(!root)
      return 1;
  	return isBST(root,INT_MIN,INT_MAX);
}


//Converts a BT into its Mirror Tree
void findMirror(struct Node* root)
{
	if(!root)
      return;
  	findMirror(root->left);
  	findMirror(root->right);
  	struct Node* temp=root->left;
  	root->left=root->right;
  	root->right=temp;
}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;

    while (current->left_child != NULL)
        current = current->left;

    return current;
}

//Delete Node In A BST
struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
    {
        printf("Node not found\n");
        return NULL;
    }

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        struct Node *temp = NULL; 
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


bool findPath(struct Node *root, vector<int> &path, int k) 
{ 
    if (root == NULL) return false; 
  
    path.push_back(root->key); 
  
    if (root->key == k) 
        return true; 
  
    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 
  
    path.pop_back(); 
    return false; 
} 
  

//Lowest Common Ancestor  
int findLCA(struct Node *root, int n1, int n2) 
{ 
    vector<int> path1, path2; 
  
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
          return -1; 
  
    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
} 
  
int diameter(struct Node* root)
{
   if (tree == NULL) 
     return 0; 
  
  int lheight = height(root->left); 
  int rheight = height(root->right); 
  
  int ldiameter = diameter(root->left); 
  int rdiameter = diameter(root->right); 
  
  return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
}

int isPalindrome(struct Node* rLeft,struct Node* rRight)
{
    if(rLeft==NULL && rRight==NULL)
    {
        return 1;
    }
    if(rLeft==NULL || rRight==NULL)
        return 0;
    return (rLeft->data == rRight->data) && checkFold(rLeft->left,rRight->right) && checkFold(rLeft->right,rRight->left);
}


int main() {
    int choice;
    cin>>choice;
    struct Node * root = NULL;
    switch (choice)
    {
        case 1:
        {    
            map < int, Node * > m;
            int n;
            scanf("%d", &n);
            
            struct Node * child;
            while (n--) {
                Node * parent;
                char lr;
                int n1, n2;
                scanf("%d %d %c", &n1, &n2, &lr);
                if (m.find(n1) == m.end()) {
                    parent = new Node(n1);
                    m[n1] = parent;
                    if (root == NULL)
                        root = parent;
                } else
                    parent = m[n1];
                child = new Node(n2);
                if (lr == 'L')
                    parent -> left = child;
                else
                    parent -> right = child;
                m[n2] = child;
            }
            break;
        }
        case 2:
        {
            int n;
            cin>>n;
            while(n--)
            {
                int x;
                cin>>x;
                root=insertBST(root,x);
            }
            break;
        }
    default:
        break;
    }
    
    // printInOrder(root);
    // printInOrderIterative(root);
    // printAllPaths(root);
    // printPreOrder(root);
    // printPreOrderIterative(root);
    // printPostOrder(root);
    // printPostOrderIterative(root);
    // printLevelOrder(root);
    // printReverseLevelOrder(root);
    // printSpiral(root);
    // printLevelOrder(root);
    // printTopView(root);
    // printBottomView(root);
    // cout<<findLCA(root,k1,k2);
    // isPalindrome(root->left,root->right);
}