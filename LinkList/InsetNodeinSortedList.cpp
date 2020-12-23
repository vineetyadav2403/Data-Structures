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
// insert node in a sorted list.
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
    while (head)
    {
        cout<<head->i;
        head = head->next;
    }
    return 0;
}