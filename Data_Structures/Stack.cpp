#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

template <typename t>
class stacks
{
	virtual void push(t d)=0;
	virtual void pop()=0;
	virtual t peak()=0;
	virtual bool empty()=0;	
};

template <typename t> 
class ArrayStack : public stacks<t>
{
	t stack[100];
	int top;	
	public:
		ArrayStack()
		{
			top=-1;
		}
		void push(t data)
		{
			if(top==100)
			{
				printf("Overflow\n");
			}
			else
			{
			top++;
			stack[top]=data;
		    }
		}
		t peak()
		{
			if(top==-1)
			{
				printf("No elements\n");
			}
			else
			{
			return stack[top];
		    }
		}
		void pop()
		{
			if(top==-1)
			{
				printf("Underflow\n");
			}
			else
			top--;
		}
		bool empty()
		{
			if(top==-1)
			{
				return true;
			}
			else
			{
				return false;
			}	
		}
};

template <typename t>
class DoubleStack : public stacks<t>{
	t stack[100];
	int top1;
	int top2;
	public:
	DoubleStack()
	{
		top1=-1;
		top2=100;
	}
	void push(t data)
	{
		if(top1==top2-1)
		{
			printf("Overflow\n");
		}
		else
		{
		top1++;
		stack[top1]=data;
	    }
    }
	void pushtail(t data)
	{
		if(top1==top2-1)
		{
			printf("Overflow\n");
		}
		else
		{
		top2--;
		stack[top2]=data;
	    }
	}
	t peak()
	{
		if(top1==-1)
		{
			printf("No elements are inserted\n");
		}
		else
		{
			return stack[top1];
		}
	}
	t peaktail()
	{
		if(top2==100)
		{
			printf("No elements are inserted\n");
		}
		else
		{
			return stack[top2];
		}
	}
	void pop()
	{
		if(top1==-1)
		{
			cout << "Underflow" << endl;
		}
		else
		{
			top1--;
		}
	}
	void poptail()
	{
		if(top2==100)
		{
			cout << "Underflow" << endl; 
		}
		else
		{
			top2++;
		}
	}
	bool empty()
	{
		if(top1==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool emptytail()
	{
		if(top2==100)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

template <typename t>
class LinkedStack : public stacks<t>
{
	public:
	struct node{
		t data;
		struct node* next;
	};
	struct node *head = NULL;
	void push(t data)
	{
		if(head==NULL)
		{
			struct node *ptr = (struct node *)malloc(sizeof(struct node));
			ptr->data=data;
			ptr->next=NULL;
			head = ptr;
		}
		else
		{
			struct node *ptr = (struct node *)malloc(sizeof(struct node));
			ptr->data = data;
			ptr->next = head;
			head = ptr;
		}
	}
	bool empty()
	{
		if(head==NULL)
		{
			return true;
		}
		else
		return false;
	}
	void pop()
	{
		head= head->next;
	}
	t peak()
	{
		return head->data;
	}
};

int main()
{
//	ArrayStack <int> s;
//	s.push(10);
//	s.peak();
//	s.pop();
//	cout << s.peak() << endl;
//	cout << s.empty() << endl;
//	
//	// DoubleSided Stack
//	
//	DoubleStack <int> d;
//	d.push(1);
//	d.pushtail(2);
//	cout << d.peak() << endl;
//	cout << d.peaktail() << endl;
//	d.pop();
//	d.poptail();
//	cout << d.empty() << endl;
//	cout << d.emptytail() << endl;
	
	// Linked Stack
	
//	LinkedStack <int> s;
//	s.push(10);
//	s.push(20);
//	cout << s.peak() << endl;
//	s.pop();
//	cout << s.peak() << endl;
//	cout << s.empty() << endl;

	
	return 0;
}
