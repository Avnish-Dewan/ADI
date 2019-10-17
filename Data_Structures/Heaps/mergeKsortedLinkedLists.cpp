#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int data;
      ListNode *next;
  };

struct ListNode * newNode(int data)
{
	ListNode * temp=new ListNode();
	temp->data=data;
	temp->next=NULL;
	return temp;
}


 struct compare{
 bool operator()(const ListNode *lhs, const ListNode *rhs)
{
    return lhs->data > rhs->data;
}
 };

struct ListNode* mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode *,vector<ListNode *>,compare> minHeap;
    for(int i=0;i<A.size();i++)
    {
        minHeap.push(A[i]);
    }
    ListNode *temp;
    ListNode *head=NULL;
    ListNode *tail=NULL;
    while(!minHeap.empty())
    {
        temp=minHeap.top();
        minHeap.pop();
        if(temp->next)
        minHeap.push(temp->next);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    return head;
}

void print(struct ListNode *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{

	   int n;
	   cin>>n;
       vector<ListNode *> arr;
       for(int j=0;j<n;j++)
        {
           int n;
           cin>>n;
           int x;
           cin>>x;
           ListNode* temp=newNode(x);
           arr.push_back(temp);
           ListNode *curr = arr[j];
           n--;
           for(int i=0;i<n;i++)
           {
               cin>>x;
               ListNode *temp = newNode(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		struct ListNode *head= mergeKLists(arr);
   		print(head);
}