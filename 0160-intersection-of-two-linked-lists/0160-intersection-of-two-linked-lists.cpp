/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* colisonPoint(ListNode* smaller, ListNode* larger, int d){
        while(d > 0 && larger != NULL){
            larger = larger->next;
            d--;
        }
        while(smaller != NULL && larger != NULL && smaller != larger){
            smaller = smaller->next;
            larger = larger->next;
        }
        return smaller;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode*, int> mpp;

        // ListNode* temp = headA;
        // while(temp != NULL){
        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }
        // temp = headB;
        // while(temp != NULL){
        //     if(mpp.find(temp) != mpp.end()){
        //         return temp;
        //     }
        //     temp = temp->next;
        // }
        // return NULL;

        if(headA == NULL || headB == NULL){
            return NULL;
        }

        ListNode* t1 = headA;
        int n1 = 0;

        ListNode* t2 = headB;
        int n2 = 0;

        while(t1 != NULL){
            n1++;
            t1 = t1->next;
        }
        while(t2 != NULL){
            n2++;
            t2 = t2->next;
        }

        if(n1<n2){
            return colisonPoint(headA,headB,(n2-n1));
        }
        else{
            return colisonPoint(headB,headA,(n1-n2));
        }
        return NULL;
    }
};