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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode* first = list1;
        ListNode* second = list2;

        while(first != NULL && second != NULL){
            if(first->val <= second->val){
                tail->next = first;
                first = first->next;
            }
            else{
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }
        
        tail->next = (first != NULL) ? first : second;
       return dummy->next;
    }
};