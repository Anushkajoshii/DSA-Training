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
    bool isPalindrome(ListNode* head) {
        //first checkif empty

        if(head== nullptr || head->next== nullptr) return true;
        ListNode* slow= head;
        ListNode* fast= head;
        //increse fast and slow by +1,+2
        while(fast !=nullptr && fast->next != nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }
        //devide list intohalft by mid
        ListNode* mid= slow;
        ListNode* prev= nullptr;
        ListNode* curr= mid;
        while(curr != nullptr){
            ListNode* temp= curr->next;
            curr->next= prev;
            prev=curr;
            curr= temp;
        }

        //compare left and right if same then it is a palindrome
        
        ListNode* left= head;
        ListNode* right=prev;
        while(right != nullptr){
            if(left->val != right->val) return false;
            left= left->next;
            right= right->next;
        }
        return true;
    }
};