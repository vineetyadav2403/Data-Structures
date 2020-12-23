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
// n is the number of player
// every mth player get eliminated
ListNode* GetJosephusPosition(int n,int m){
    ListNode *p,*q;
    p = q = new ListNode();
    p->i = 1;
    for(int i=2;i<=n;i++){
        p->next = new ListNode(i);
    }
    p->next = q;
    for(int c = n;c > 1; --c){
        for(int i = 0;i<m;i++)
            p = p->next;
        p->next = p->next->next;
    }
    return p;

}

int main(){
    
    cout<<GetJosephusPosition(10,3)->i;
    return 0;
}