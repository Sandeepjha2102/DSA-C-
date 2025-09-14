/**
 * Definition for singly-linked list.
 * struct Li
 stNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Helper function to reverse a linked list from head to tail
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while (prev != tail) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return tail;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while (true) {
            // find kth node
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break; // less than k nodes remain

            ListNode* groupStart = prevGroup->next;
            ListNode* groupEnd = kth;
            ListNode* nextGroup = kth->next;

            // reverse the group
            reverse(groupStart, groupEnd);

            // reconnect links
            prevGroup->next = groupEnd;
            groupStart->next = nextGroup;

            // move prevGroup
            prevGroup = groupStart;
        }
        return dummy.next;
    }
};
