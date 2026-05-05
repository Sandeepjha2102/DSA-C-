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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int size = 1;
        ListNode* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
            size++;
        }
        temp->next = head;

        int num = size - (k%size);
        ListNode* prev = head;
        int count = 1;

        while(count < num ){    
            prev = prev->next;
            num--;
        }
        ListNode* curr = prev->next;
        prev->next = NULL;
        return curr;
    }
};