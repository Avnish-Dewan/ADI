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

        int detectAndRemoveLoop() 
        { 
            struct Node *slow = head, *fast = head; 
        
            while (slow && fast && fast->next) { 
                slow = slow->next; 
                fast = fast->next->next; 
        
                if (slow == fast) { 
                    removeLoop(slow, head); 
        
                    return 1; 
                } 
            } 
        
            return 0; 
        } 
        void removeLoop(struct Node* slow, struct Node* head) 
        { 
            struct Node* ptr1 = slow; 
            struct Node* ptr2 = slow; 
        
            unsigned int k = 1, i; 
            while (ptr1->next != ptr2) { 
                ptr1 = ptr1->next; 
                k++; 
            } 
        
            ptr1 = head; 
        
            ptr2 = head; 
            for (i = 0; i < k; i++) 
                ptr2 = ptr2->next; 
        
            while (ptr2 != ptr1) { 
                ptr1 = ptr1->next; 
                ptr2 = ptr2->next; 
            } 
        
            while (ptr2->next != ptr1) 
                ptr2 = ptr2->next; 
        
            ptr2->next = NULL; 
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
    ll.insert(2);
    ll.insert(1);
    cout<<ll.detectAndRemoveLoop();
    ll.printList();
}
