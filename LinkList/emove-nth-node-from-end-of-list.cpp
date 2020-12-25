https://leetcode.com/problems/remove-nth-node-from-end-of-list/


ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode *p = head;

        while (p) // find length
        {
            length++;
            p = p->next;
        }

        if (n == length) // check if need to remove the first node
            return head->next;

        length -= n;
        length--;

        p = head;
        while (length--) // get p the node before the n-th from the end
            p = p->next;
        p->next = p->next->next; // the move the node

        return head;
    }
