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

     bool checkPalindrome(struct Node* head, struct Node* &temp)
        {
            if(!head)
                return true;

            bool x = checkPalindrome(head->next , temp);
            if(!x)
                return false;
            bool y = (temp->data == head->data);
            temp=temp->next;
            return y;
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

       
        bool isPalindrome()
        {
            struct Node* temp = head;
            return checkPalindrome(head,temp);
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

    cout<<ll.isPalindrome();
    // ll.printList();
}
