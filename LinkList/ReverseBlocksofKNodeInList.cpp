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

ListNode *reverse (ListNode *head, int k)  
{  
    ListNode* current = head;  
    ListNode* next = NULL;  
    ListNode* prev = NULL;  
    int count = 0;  
      
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
    /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (next != NULL)  
    head->next = reverse(next, k);  

    /* prev is new head of the input list */
    return prev;  
}  
int main(){
    ListNode *head = new ListNode(1),*t;
    t = head;
    for(int i=2;i<=15;i++){
        ListNode * temp = new ListNode(i);
        t->next = temp;
        t=temp;
    }
    head = reverse(head,4);
    while (head)
    {
        cout<<head->i<<" ";
        head = head->next;
    }
    
    return 0;
}