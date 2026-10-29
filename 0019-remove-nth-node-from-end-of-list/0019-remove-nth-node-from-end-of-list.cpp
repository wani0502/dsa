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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        int count=0;
        ListNode* curr=head;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        if(count==n){
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        curr=head;
        for(int i=1;i<count-n;i++){
            curr=curr->next;
        }
        ListNode* prev=curr->next;
        if(prev){
            curr->next=prev->next;
            delete prev;
        }
        return head;

    }
};