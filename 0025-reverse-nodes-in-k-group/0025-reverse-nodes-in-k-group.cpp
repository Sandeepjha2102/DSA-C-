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
    // // Helper function to reverse a linked list from head to tail
    // ListNode* reverse(ListNode* head, ListNode* tail) {
    //     ListNode* prev = tail->next;
    //     ListNode* curr = head;
    //     while (prev != tail) {
    //         ListNode* nxt = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = nxt;
    //     }
    //     return tail;
    // }

    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if (!head || k == 1) return head;

    //     ListNode dummy(0);
    //     dummy.next = head;
    //     ListNode* prevGroup = &dummy;

    //     while (true) {
    //         // find kth node
    //         ListNode* kth = prevGroup;
    //         for (int i = 0; i < k && kth; i++) {
    //             kth = kth->next;
    //         }
    //         if (!kth) break; // less than k nodes remain

    //         ListNode* groupStart = prevGroup->next;
    //         ListNode* groupEnd = kth;
    //         ListNode* nextGroup = kth->next;

    //         // reverse the group
    //         reverse(groupStart, groupEnd);

    //         // reconnect links
    //         prevGroup->next = groupEnd;
    //         groupStart->next = nextGroup;

    //         // move prevGroup
    //         prevGroup = groupStart;
    //     }
    //     return dummy.next;


    //REVERSE THE LINKED LIST

    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k){
        k -=1;
        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;

        while(temp != NULL){
            ListNode* kThNode = getKthNode(temp, k);
            if(kThNode == NULL){
                prevlast->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;

            reverseLinkedList(temp);

            if(temp == head){
                head = kThNode;
            }
            else{
                prevlast->next = kThNode;
            }
            prevlast = temp;
            temp = nextNode;
            }
            return head;
    }
};
