/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr) {
            return nullptr;
        }

        // Step 1: Copy node ko original node ke baad insert karo
        Node* curr = head;

        while (curr != nullptr) {

            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Random pointers set karo
        curr = head;

        while (curr != nullptr) {

            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // Step 3: Original aur copy list separate karo
        curr = head;

        Node* copyHead = head->next;

        while (curr != nullptr) {

            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }

            curr = curr->next;
        }

        return copyHead;
    }
};