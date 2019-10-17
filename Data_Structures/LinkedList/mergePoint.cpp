
struct Node* findMergePoint(struct Node* head1, struct Node* head2) 
{
	while(head1!=NULL)
    {
      struct Node* temp=head2;
      while(temp!=NULL)
      {
        if(head1==temp)
        {
          return head1;
        }
        temp=temp->next;
      }
      head1=head1->next;
    }
  	return NULL;
}
