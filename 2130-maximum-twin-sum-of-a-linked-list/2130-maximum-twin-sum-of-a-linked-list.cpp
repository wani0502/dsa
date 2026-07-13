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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast) slow=slow->next;
        ListNode* prev=nullptr;
        ListNode* curr=slow;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        int maxi=0;
        int sum=0;
        while(prev){
            sum=prev->val+head->val;
            maxi=max(sum,maxi);
            prev=prev->next;
            head=head->next;
        }
        return maxi;
    }
};