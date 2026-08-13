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
    void reorderList(ListNode* head) {
        if (!head || !head->next){
            return;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while (fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=slow->next;
        slow->next=nullptr;
        while (curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        ListNode* c1=head;
        ListNode* c2=prev;
        while (c2){
            ListNode* temp=c1->next;
            ListNode* temp2=c2->next;
            c1->next=c2;
            c2->next=temp;
            c1=temp;
            c2=temp2;
        }
    }
};