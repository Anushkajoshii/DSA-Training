//GFG
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeTwoLists(Node *head1, Node *head2)
    {
        if(head1 == NULL)
            return head2;
        if(head2 == NULL)
            return head1;
        if(head1 -> data > head2 -> data)
            swap(head1, head2);
        Node *ans = head1;
        while(head1 && head2)
        {
            Node *temp = NULL;
            while(head1 && head1 -> data <= head2 -> data)
            {
                temp = head1;
                head1 = head1 -> next;
            }
            temp -> next = head2;
            swap(head1, head2);
        }
        return ans;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
        // Your code here
        if(K == 1)
            return arr[0];
        Node *ans = mergeTwoLists(arr[0], arr[1]);
        for(int i = 2; i < K; i++)
            ans = mergeTwoLists(ans, arr[i]);
        return ans;
    }
};

//Leetcode
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //collect all nodes
        vector<ListNode*> nodes;
        for(ListNode*list:lists){
            while(list!= nullptr){
                nodes.push_back(list);
                list=list->next;
            }
        }
        //sort the nodes onvalues
        sort(nodes.begin(), nodes.end(), [] (ListNode* a,ListNode* b){
            return a->val < b->val;
        });
        //reconstruct ll
        if(nodes.empty()){
            return nullptr;
        }
        ListNode* head= nodes[0];
        ListNode* curr= head;
        for(int i=1; i<nodes.size(); i++){
            curr->next = nodes[i];
            curr= curr->next;
        }
        curr->next= nullptr;
        return head;
    }
};