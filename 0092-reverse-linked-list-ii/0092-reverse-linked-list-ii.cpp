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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) 
        return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* beforeLeft = dummy;

        for(int i = 1; i < left; i++){
            beforeLeft = beforeLeft->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = beforeLeft->next;
        ListNode* leftHead = curr;

        for(int i = 0; i <= right-left; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }


        beforeLeft->next = prev;
        leftHead->next = curr;

        return dummy->next;
    }
};