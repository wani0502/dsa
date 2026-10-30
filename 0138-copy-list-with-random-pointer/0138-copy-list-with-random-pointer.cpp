class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*,Node*> m;
        Node* newhead=new Node(head->val);
        Node* oldtemp=head->next;
        Node* newtemp=newhead;
        m[head]=newhead;
        while(oldtemp){
            Node* copynode=new Node(oldtemp->val);
            m[oldtemp]=copynode;
            newtemp->next=copynode;
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        oldtemp=head;
        newtemp=newhead;
        while(oldtemp){
            newtemp->random=m[oldtemp->random];
            oldtemp=oldtemp->next;
            newtemp=newtemp->next;
        }
        return newhead;
    }
};