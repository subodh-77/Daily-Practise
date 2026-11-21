
class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Merge both halves
        ListNode* first = head;
        ListNode* second = prev;

        while(second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
