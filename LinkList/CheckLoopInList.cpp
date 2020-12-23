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
/* check whether the given linked list is either NULL - terminated or ends in a cycle */
bool DoesLinkListContainsLoop(ListNode * head){
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr==fastPtr) return true;
    }

    return false;
}
/* find the start node of the loop */
ListNode* FindBeginofLoop(ListNode *head){
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;
    bool isLoop = false;
    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr == fastPtr){
            isLoop = true;
            break;
        }
    }
    if(isLoop){
        slowPtr = head;
        while(slowPtr!=fastPtr){
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
    return NULL;
}
// find the length of the loop

int FindLengthofLoop(ListNode* head){
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;
    bool isLoop = false;
    int counter = 0;
    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr == fastPtr){
            isLoop = true;
            break;
        }
    }
    if(isLoop){
        fastPtr = fastPtr->next;
        while(slowPtr!=fastPtr){
            fastPtr = fastPtr->next;
            counter++;
        }
        return counter;
    }
    return 0;
}
// 

int main(){
    ListNode *head = new ListNode(1);
    ListNode *a = new ListNode(2);
    head->next = a;
    ListNode *b = new ListNode(3);
    a->next = b;
    b->next = head;
    cout<<FindLengthofLoop(head);
    return 0;
}