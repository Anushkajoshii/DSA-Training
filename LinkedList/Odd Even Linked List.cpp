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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next== nullptr || head->next->next== nullptr) return head;
        ListNode* odd= head;
        ListNode* even= head->next;
        ListNode* even_start= head->next;
        while(odd->next && even->next){
            odd->next= even->next; //connect all odds
            even->next= odd->next->next; //connect all evens
            odd= odd->next;
            even= even->next;
        }
        odd->next= even_start; //place even after odd
        return head;
    }
};