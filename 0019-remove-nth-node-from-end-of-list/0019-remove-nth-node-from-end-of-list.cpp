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
        if(head -> next == NULL){
            return NULL;
        }

        ListNode* temp = head;
        int size = 1;
        while(temp -> next != NULL){
            temp = temp -> next;
            size++;
        }

        ListNode* prev = NULL;
        temp = head;
        int count = 0;
        if(size - count == n){
            return head->next;
        }
        while (size-count != n){
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev -> next = temp -> next;
        delete(temp);
        return head;
    }
};