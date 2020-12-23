#include<iostream>
using namespace std;
class ListNode{
    public:
    int i;
    ListNode* next;
    ListNode(int i){
        this->i = i;
        this->next = NULL;
    }
    ListNode(){
        this->i = 0;
        this->next = NULL;
    }
};
// Reverse a singly link List. 
ListNode* ReverseList(ListNode* head){
    ListNode *temp=NULL,*nextNode = NULL;
    while (head)
    {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    return temp;
}
// Insert node in sorted list.
ListNode* InsetInSortedList(ListNode* head, ListNode* node){
    ListNode *current = head,*temp = NULL;
    if(!head) return node;
    while (current!=NULL&&current->i < node->i){
        temp = current;
        current = current->next;
    }
    node->next = current;
    if(temp){
        temp->next = node;
    }else{
        return node;
    }
    return head;
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode *a = new ListNode(2);
    head->next = a;
    ListNode *b = new ListNode(4);
    a->next = b;
    head = InsetInSortedList(head,new ListNode(3));
    head = InsetInSortedList(head,new ListNode(0));
    head = ReverseList(head);
    while (head)
    {
        cout<<head->i;
        head = head->next;
    }
    return 0;
}