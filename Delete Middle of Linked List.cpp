class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Starting from here
        Node* fast=head, *slow=head, *prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(head->next == NULL){
            return NULL;
        }
        prev->next=slow->next;
        return head;
    }
};
