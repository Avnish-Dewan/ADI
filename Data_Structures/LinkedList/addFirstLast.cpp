#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};
void print(struct Node *ptr){
	while(ptr!=NULL){
		cout<<ptr->data;
		ptr=ptr->next;
	}
	cout<<"\n";
}
void addFirstLast(struct Node *head,struct Node *slow,struct Node *fast){
	static struct Node *temp=NULL;
	static struct Node *temp1=NULL;
	if(fast==NULL){
		temp1=slow;
		return;
	}
	if(fast->next==NULL){
		temp1=slow->next;
		return;
	}
	addFirstLast(head,slow->next,fast->next->next);
	int sum=(slow->data)+(temp1->data);
	slow->data=sum;
	temp1->data=sum;
	temp1=temp1->next;
}


int main(){
	int d,i=0;
	printf("Press -1 To End insertion Operation\n");
	struct Node *head;
	struct Node *ptr;
	scanf("%d",&d);
	while(d!=-1){
		if(i==0){
			head=(struct Node *)malloc(sizeof(struct Node));
			head->data=d;
			head->next=NULL;
			ptr=head;
		}
		else{
			struct Node *temp=(struct Node *)malloc(sizeof(struct Node ));
			temp->data=d;
			temp->next=NULL;
			ptr->next=temp;
			ptr=ptr->next;
			
		}
		i++;
		scanf("%d",&d);
	}
	struct Node *slow=head,*fast=head;
	addFirstLast(slow,fast,head);
	print(head);
	return 0;
}
