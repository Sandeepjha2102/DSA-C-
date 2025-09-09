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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int m1 = count / 2;
        temp = head;

        while(temp != NULL){
            m1--;
            if(m1 == 0){
                break;
            }
            temp = temp ->next;
        }
        ListNode* mid = temp->next;
        temp -> next = mid->next;
        delete(mid);
        return head;
    }
};