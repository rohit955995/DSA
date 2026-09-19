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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans(k, nullptr);

        // Step 1: Count total nodes
        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        // Step 2: Find basic size and extra nodes
        int baseSize = n / k;
        int extra = n % k;

        ListNode* curr = head;

        // Step 3: Create k parts
        for (int i = 0; i < k; i++) {

            ans[i] = curr;

            int partSize = baseSize;

            if (extra > 0) {
                partSize++;
                extra--;
            }

            // Move to last node of current part
            for (int j = 1; j < partSize && curr != nullptr; j++) {
                curr = curr->next;
            }

            // Break current part
            if (curr != nullptr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }

        return ans;
    }
};