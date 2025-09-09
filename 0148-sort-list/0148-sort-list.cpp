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
    ListNode* sortList(ListNode* head) {
        vector<int> ls;
        ListNode* temp = head;

        while(temp!= NULL){
            ls.push_back(temp->val);
            temp = temp -> next;
        }

        sort(ls.begin(), ls.end());
        temp = head;

        for(int i = 0; i<ls.size(); i++){
            temp->val = ls[i];
            temp = temp->next;
        }
        return head;
    }
};