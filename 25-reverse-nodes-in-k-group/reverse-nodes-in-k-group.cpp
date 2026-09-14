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

        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Step 1: Check k nodes available hain?
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {

                kth = kth->next;

                if (kth == nullptr) {
                    return dummy->next;
                }
            }

            // Group ka next part
            ListNode* groupNext = kth->next;

            // Step 2: Reverse k nodes
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {

                ListNode* nextNode = curr->next;

                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Step 3: Reconnect
            ListNode* oldGroupStart = groupPrev->next;

            groupPrev->next = kth;

            // Old first node ab group ka last node hai
            groupPrev = oldGroupStart;
        }

        return dummy->next;
    }
};