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
        if(head == NULL || k==0) return head;
        ListNode* tail = head;
        int length = 1;

        while(tail->next != NULL){
            length++;
            tail = tail->next;
        }

        cout << length;
        if(k % length == 0 ) return head;

        tail->next = head;

        ListNode* temp = head;

        k = k%length;

        int lenCount = length-k;
        int count = 0;

        while (temp != NULL){
        count++;
        if(count == lenCount){
            break;
        }   
        temp = temp->next;
    }
    head = temp->next;
            temp->next = NULL;
    return head;
    }
};