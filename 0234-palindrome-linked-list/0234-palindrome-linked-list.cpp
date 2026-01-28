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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;

        vector<int> values;
        ListNode* temp = head;
        int i = 0;

        while(temp != NULL){
            values.push_back(temp->val);
            temp = temp->next;
            i++;
        }
        int left = 0;
        int right = values.size()-1;

        while(left < right){
            if(values[left] == values[right]){
                left++;
                right--;
                continue;

            }
            else{
                return false;
            }
        }
        return true;
    }
};