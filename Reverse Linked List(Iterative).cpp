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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        else if(!head->next) return head;
        else {
            ListNode* prev=head;
            ListNode* curr=prev->next;
            ListNode* latest=curr->next;
            
            prev->next=NULL;
            
            while(latest){
                curr->next=prev;
                prev=curr;
                curr=latest;
                latest=latest->next;
            }
            
            curr->next=prev;
            return curr;
            
            // O(n)
            // O(1)
            
        }
    }
};
