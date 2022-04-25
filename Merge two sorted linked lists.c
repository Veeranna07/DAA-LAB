// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    SinglyLinkedListNode* mergedHead = NULL;
    SinglyLinkedListNode* mergedTail = NULL;
    while(head1!=NULL && head2 !=NULL)
    {
      if (head1->data <= head2->data) {
      if(mergedTail == NULL)
      {
          mergedHead = head1;
          mergedTail = head1;
      }
      else
      {
          mergedTail->next=head1;
          mergedTail = head1;
      }
         
      head1 = head1->next;
    } else {
     
      if(mergedTail == NULL)
      {
          mergedHead = head2;
          mergedTail = head2;
      }
      else
      {
          mergedTail->next=head2;
          mergedTail = head2;
      }    
      head2 = head2->next;
    }
    }
   
    while(head1 != NULL) {
      mergedTail->next = head1;
    mergedTail = head1;
       head1 = head1->next;
    }
    while (head2 != NULL) {
      mergedTail->next = head2;
        mergedTail = head2;
        head2=head2->next;
    }


    return mergedHead;
}
