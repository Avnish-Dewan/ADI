#include<bits/stdc++.h>

using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        struct Node* next;
        Node(int d)
        {
            data=d;
            next=NULL;
        }
    };
    struct Node* head = NULL;
    int size;

    public:
        LinkedList()
        {
            head=NULL;
            size=0;
        }
        void insert(int data)
        {
            if(!head)
            {
                head=new struct Node(data);
                return;
            }
            struct Node* curr=head;
            while(curr->next)
            {
                curr=curr->next;
            }
            curr->next = new struct Node(data);
        }

        int findMiddle()
        {
            if(head!=NULL)
            {
      	        struct Node* mid=head;
                struct Node* temp=head;
                while(temp!=NULL && temp->next!=NULL)
                {
                    mid=mid->next;
                    temp=temp->next->next;
                }
                return mid->data;
            }
            else
            {
                return -1;
            }
        }

        int findNthFromLast(int n)
        {
            struct Node *curr = head; 
            struct Node *ref = head; 
            
            int count = 0; 
            if(head != NULL) 
            { 
                while( count < n ) 
                { 
                    if(ref == NULL) 
                    { 
                        return -1;
                    } 
                    ref = ref->next; 
                    count++; 
                } 
            
                while(ref != NULL) 
                { 
                    curr = curr->next; 
                    ref  = ref->next; 
                } 
                return curr->data; 
            } 
            return -1;
        }
        void printList()
        {
            struct Node* curr=head;

            while(curr)
            {
                cout<<curr->data<<" ";
                curr=curr->next;
            }
            cout<<endl;
        }
};

int main()
{
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);

    cout<<ll.findMiddle()<<endl;
    cout<<ll.findNthFromLast(5)<<endl;

    ll.printList();
}
