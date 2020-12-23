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
// find the middle node of the link list.
ListNode* FindMiddleofList(ListNode* head){
    ListNode *ptrx1,*ptrx2;
    ptrx1 = ptrx2 = head;
    int i=0;
    while(ptrx1->next!=NULL){
        if(i==0){
            ptrx1 = ptrx1->next;
            i=1;
        }else{
            ptrx1 = ptrx1->next;
            ptrx2 = ptrx2->next;
            i=0;
        }
    }
    return ptrx2;
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode *a = new ListNode(2);
    head->next = a;
    ListNode *b = new ListNode(3);
    a->next = b;

    cout<<FindMiddleofList(head)->i;
    return 0;
}