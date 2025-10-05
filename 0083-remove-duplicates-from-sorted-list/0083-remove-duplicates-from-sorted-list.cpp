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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = head;
        ListNode* front = head->next;
        while(front != NULL){
            if(prev->val == front->val){
            prev->next = front->next;
        }
        else{
            prev=prev->next;
        }
        front = front->next;
        }
        return head;
    }
};