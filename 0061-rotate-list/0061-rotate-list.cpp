/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int count=1;
        ListNode* tail=head;
       
        while(tail->next){
            tail=tail->next;
            count++;
        }
        k=k%count;
        if(k==0) return head;
        tail->next=head;
        ListNode* newtail=head;
        for(int i=0;i<count-k-1;i++){
            newtail=newtail->next;        
        }
        ListNode* newhead=newtail->next;
        newtail->next=nullptr;
        return newhead;
    }
};