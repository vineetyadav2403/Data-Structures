#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int i;
    ListNode* next,*rand;
    ListNode(int i){
        this->i = i;
        this->next = NULL;
        this->rand = NULL;
    }
    ListNode(){
        this->i = 0;
        this->next = NULL;
        this->rand = NULL;
    }
};
// time O(n), space O(n)
ListNode* Clone(ListNode* head){
    ListNode *x,*y;
    unordered_map<ListNode*,ListNode*> mp;
    x = head;
    while (x!=NULL)
    {
        y = new ListNode(x->i);
        mp[x] = y;
        x = x->next;
    }
    x = head;
    while (x!=NULL)
    {
        y=mp[x];
        y->next = mp[x->next];
        y->rand = mp[x->rand];
        x = x->next;
    }
    return mp[head];
}

// time O(n), space O(1)
void clone(ListNode* head){
    //TODO 
}