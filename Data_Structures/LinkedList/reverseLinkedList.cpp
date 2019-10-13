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

    struct Node* reverse(struct Node* head)
    {
         if (head == NULL || head->next == NULL) 
            return head; 
  

        Node* rest = reverse(head->next); 
        head->next->next = head; 
  
        head->next = NULL; 
  
        return rest; 
    }

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

        void reverseUsingStack()
        {
            stack<struct Node*> st;
            struct Node* curr=head;
            while(curr)
            {
                st.push(curr);
                curr=curr->next;
            }
            // cout<<st.top();
            curr=st.top();
            st.pop();
            head = curr; 
            while (!st.empty()) { 
                curr->next = st.top(); 
  
                curr = curr->next; 
                st.pop(); 
            } 
            curr->next = NULL; 
        }

        void reverseIterative()
        {
            struct Node* current = head; 
            struct Node *prev = NULL, *next = NULL; 
  
            while (current != NULL) { 
                next = current->next; 
    
                current->next = prev; 
    
                prev = current; 
                current = next; 
            } 
            head = prev; 
        } 

        void reverseRec()
        {
            head = reverse(head);
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
    // ll.reverseIterative();
    // ll.reverseUsingStack();
    ll.reverseRec();

    ll.printList();
}
