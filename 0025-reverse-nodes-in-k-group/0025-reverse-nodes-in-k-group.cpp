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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        //Checking kth nodes are present or not
        while(cnt < k){
            if(temp == NULL) return head;
            temp = temp->next;
            cnt++;
        }

        //use recursive call to get next connecting node
        ListNode* prevNode = reverseKGroup(temp, k);

        //connectinh curr nodes
        temp = head;
        cnt = 0;

        while(cnt < k){
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }
        return prevNode;
    }
};