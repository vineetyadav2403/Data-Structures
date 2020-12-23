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

void frontBackSplit(ListNode *source,ListNode **frontRef,ListNode **backRef){
    ListNode *slow = source,*fast=source->next;
    while (fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
    
}
ListNode* sortedMerge(ListNode *a,ListNode *b){
    ListNode *dummy = new ListNode();
    ListNode *last = dummy;
    while (a!=NULL && b!=NULL)
    {
        if(a->i<b->i){
            last->next = a;
            a = a->next;
            last = last->next;
        }else{
            last->next = b;
            b = b->next;
            last = last->next;
        }
    }
    if(a!=NULL)
        last->next = a;
    if(b!=NULL)
        last->next = b;

    return dummy->next;
}
void mergeSort(ListNode **headRef){
    ListNode* head = *headRef;
    ListNode* a, *b;
    if((head==NULL)||(head->next==NULL)) return;
    frontBackSplit(head,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = sortedMerge(a,b);
}
int main(){
    ListNode * head = new ListNode(1),*a ,*b,*c;
    a = new ListNode(4);
    b = new ListNode(20);
    c = new ListNode(10);
    head->next = a;
    a->next = b;
    b->next = c;
    mergeSort(&head);
    while (head)
    {
        cout<<head->i<<" ";
        head = head->next;
    }
    return 0;
}