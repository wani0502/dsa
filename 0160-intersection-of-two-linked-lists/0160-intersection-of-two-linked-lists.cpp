class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        
        while (ptr1 != ptr2) {
            ptr1 = (ptr1 != NULL) ? ptr1->next : headB;
            ptr2 = (ptr2 != NULL) ? ptr2->next : headA;
        }
        
        return ptr1;
    }
};